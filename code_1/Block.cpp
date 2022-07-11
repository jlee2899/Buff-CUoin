#include<iostream>
#include <sstream>


#include "Transaction.hpp"
#include "Block.hpp"
#include "sha256.hpp"

using namespace std;

Block::Block(vector<Transaction> _transactions, time_t _timestamp, string _previousHash){
    nonce = -1;
    transactions = _transactions;
    previousHash = _previousHash;
    timestamp = _timestamp;
    hash = calculateHash();
}

void Block::setPreviousHash(string _previousHash){
    previousHash = _previousHash;
}

string Block::getPreviousHash(){
    return previousHash;
}

string Block::getHash(){
    return hash;
}

time_t Block::getTimestamp(){
    return timestamp;
}

string Block::calculateHash(){
    string stringOfData;
    string SHA;
    stringstream ss;
    ss << nonce << "-" << toString() << "-" << previousHash << "-" << timestamp;

    stringOfData = ss.str();
    SHA = sha256(stringOfData);

    return SHA;   
}

void Block::mineBlock(unsigned int difficulty){
    char zero[difficulty + 1];

    for(unsigned int i = 0; i < difficulty; i++){
        zero[i] = '0';
    }

    zero[difficulty] = '\0';

    string predefinedZeroes(zero);

    do {
        nonce++;
        hash = calculateHash();
    } while(hash.substr(0, difficulty) != predefinedZeroes);
}

string Block::toString(){
    //Convert the vector of transactions as a string
    stringstream trans;
    
    for(size_t i = 0; i < transactions.size(); i++){ 
        trans << transactions[i].toString();
    }

    return trans.str();    
}