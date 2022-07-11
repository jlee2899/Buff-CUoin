#include <iostream>
#include <fstream>
#include "../code_1/Blockchain.hpp"

using namespace std;

void displayMenu(){
    cout << "====== Main Menu ======" << endl;
    cout << "1. Add a transaction" << endl;
    cout << "2. Verify Blockchain" << endl;
    cout << "3. Mine Pending Transactions" << endl;
    cout << "4. Get Balance" << endl;
    cout << "5. Print blockchain" << endl;
    cout << "6. Quit" << endl;
    cout << "-----------------------" << endl;
    cout << "#< ";
}

int main(int argc, char* argv[]){
    /*
    Blockchain buffCUoin;
    
    buffCUoin.prettyPrint(); 

    cout << "ashutosh mining first block ... " << endl;
    buffCUoin.minePendingTransactions("ashutosh");
    buffCUoin.prettyPrint(); 
    
    cout << "ashutosh paid maciej 1 BFC ... " << endl;
    buffCUoin.addTransaction("ashutosh","maciej", 1);

    cout << "ashutosh paid asa 1 BFC ... " << endl;
    buffCUoin.addTransaction("ashutosh","asa", 1);
    cout << "asa mining second block ... " << endl;
    buffCUoin.minePendingTransactions("asa");
    buffCUoin.prettyPrint(); 
    
    cout << "asa paid ashutosh 1 BFC ... " << endl;
    buffCUoin.addTransaction("asa","ashutosh", 1);    
    cout << "ashutosh paid maciej 2 BFC ... " << endl;
    buffCUoin.addTransaction("ashutosh","maciej", 2);
    
    cout << "maciej mining third block ... " << endl;
    buffCUoin.minePendingTransactions("maciej");
    buffCUoin.prettyPrint(); 
    
    cout << "ashutosh mining fourth block ... " << endl;
    buffCUoin.minePendingTransactions("ashutosh");
    buffCUoin.prettyPrint();
    */

    Blockchain buffCUoin;
    int menu = 0;
    string address;
    string minerAddress;
    string sender;
    string receiver;
    int amount;
    bool verify = false;

    while(menu != 6){
        displayMenu();
        cin >> menu;

        switch(menu){
            case 1: //Add a transaction
                cout << "Enter sender name: " << endl;
                cin >> sender;
                cout << "Enter receiver name: " << endl;
                cin >> receiver;
                cout << "Enter the amount: " << endl;
                cin >> amount;
                cout << endl;
                buffCUoin.addTransaction(sender, receiver, amount);
                cout << endl;
                break;
            case 2: //Verify Blockchain
                cout << "Verifying the blockchain...." << endl;
                verify = buffCUoin.isChainValid();
                if(verify == false){
                    cout << "Blockchain is not verified!" << endl;
                }
                else{
                    cout << "Blockchain has been verified and is secure!" << endl;
                }
                cout << endl;
                break;
            case 3: //Mine Pending Transaction
                cout << "Enter miner name: " << endl;
                cin >> minerAddress;
                cout << minerAddress << " is mining a block" << endl; 
                buffCUoin.minePendingTransactions(minerAddress);
                cout << minerAddress << " will be rewarded 10 BFC after the next pending transaction has been mined and verified.." << endl;
                cout << endl;
                break;
            case 4: //Get balance
                cout << "Enter the address you want to check the balance of: ";
                cin >> address;
                cout << endl;
                cout << "The balance of " << address << " is " << buffCUoin.getBalanceOfAddress(address) << endl;
                cout << endl;
                break;
            case 5: //Printing blockchain
                cout << "Printing the contents of every block in the blockchain...." << endl;
                cout << endl;
                buffCUoin.prettyPrint();
                break;
            case 6: //Quit
                cout << "Quitting..." << endl;
                cout << endl;
                break;
            default:
                cout << "Invalid input! Enter a number between 1-6" << endl;
                cout << endl;
                break;
        }
    }

    return 0;
}

