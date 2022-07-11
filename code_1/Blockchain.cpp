#include<iostream>
#include <sstream>

#include "Transaction.hpp"
#include "Block.hpp"
#include "Blockchain.hpp"
#include<vector>

using namespace std;

Blockchain::Blockchain(){
    Transaction genesis("BFC","BFC",0);
    pending.push_back(genesis);

    Block gBlock(pending, time(nullptr), "In the beginning..");
    chain.push_back(gBlock);

    Transaction freeMoney("BFC","make money by mining",0);
    pending.push_back(freeMoney);

    difficulty = 4;
    miningReward = 10;
}

Block Blockchain::getLatestBlock(){ 
    return chain.back();
}

void Blockchain::addTransaction(string src, string dst, int coins){
    if(getBalanceOfAddress(src) > coins){
        Transaction newTransaction(src, dst, coins);
        pending.push_back(newTransaction);
        cout << "Your transaction of " << coins << " BFC has been successful!" << endl;
        cout << "Your balance will be updated after the transaction has been verified." << endl;
    }
    
    else{
        cout << "Error, balance is not enough to transfer " << coins << " BFC." << endl;
    }
}

bool Blockchain::isChainValid(){ 
    for(size_t i = 1; i < chain.size(); i++){
        Block currNode = chain[i];
        Block prevNode = chain[i - 1];

        //Verifying if previous hash value == current's previous hash value
        if(prevNode.calculateHash() != currNode.getPreviousHash()){
            //cout << "Invalid Hash match!" << endl;
            return false;
        }

        if(currNode.calculateHash() != currNode.getHash()){
            return false;
        }
    }
    /*
    string hashCheck;
    unsigned int counter = 0;

    for(size_t i = 1; i < chain.size(); i++){
        Block currNode = chain[i];
        hashCheck = currNode.getHash();
        for(long unsigned int j = 0; j < difficulty; j++){
            if(hashCheck[j] == 0){
                counter++;
            }
        }
        if(counter != difficulty){
            //cout << "Invalid #difficulty match of hash code!" << endl;
            return false;
        }
    }
    */

    return true;
}

bool Blockchain::minePendingTransactions(string minerAddress){
    //vector <Transaction> transactions = pending;
    Block newBlock(pending, time(nullptr), getLatestBlock().getHash());
    newBlock.mineBlock(4);

    pending.clear();
    chain.push_back(newBlock);

    //addTransaction("BFC", minerAddress, 10);
    //Add a new transaction to the list of pending transactions
    Transaction reward ("BFC", minerAddress, miningReward);
    pending.push_back(reward);
    return true;
}

int Blockchain::getBalanceOfAddress(string address){
    int totalBalance = 0;

    for(size_t i = 0; i < chain.size(); i++){
        for(size_t j = 0; j < chain[i].transactions.size(); j++){
            if(chain[i].transactions[j].getSender() == address){
                totalBalance -= chain[i].transactions[j].getAmount();
            }
            if(chain[i].transactions[j].getReceiver() == address){
                totalBalance += chain[i].transactions[j].getAmount();
            }
            if(totalBalance < 0){
                cout << "Balance is NEGATIVE!" << endl;
                break; //Check
            }
        }
    }

    return totalBalance;
}

void Blockchain::prettyPrint(){
    for(size_t i = 0; i < chain.size(); i++){
            cout << "Block " << i + 1 << endl;
            cout << "Hash: " << chain[i].getHash() << endl;
            cout << "Previous Hash: " << chain[i].getPreviousHash() << endl;
            cout << "Timestamp: " << chain[i].getTimestamp() << endl;
        for(size_t j = 0; j < chain[i].transactions.size(); j++){
            cout << "Transaction " << j + 1 << ": " << chain[i].transactions[j].toString() << endl;
        }
        cout << endl;
    }
}