# CSCI 2270 – Data Structures - Buff-CUoin 

This project is an implementation of a blockchain in c++. Buff-CUoin is the blockchain containing a list of nodes called Blocks. 
Each Block will consist data of list of transactions, hashcode, previous block's hashcode, timestamp, and nonce. Within the list of transactions will
contain a sender, receiver, and the amount of Buff-CUoin. The blockchain will be interacted with a text-based surface.

The interface will include basic functionality:
> 1. Adding a transaction
> 2. Mining pending transactions
> 3. Verifying the blockchain
> 4. Checking the balance of a given user
> 5. Printing the blockchain

# Blockchain Object
**Private Data Members**
- unsigned int difficulty
  - Difficulty level used to compute the #0s in the hashcode
- chain - vector of Block
  - Blockchain list  
- pending - vector of Transaction
  - List of pending transactions to be mined   
- int miningReward
  - #Buff-CUoin rewared for mining a block

**Member Functions**
- addTransaction
  - Adds a transaction to the list of pending transactions after checking if the user has enough balance  
  - Transaction will be validated once it gets "mined"
- isChainValid
  - Validates the transactions and checks if the chain has not been tampered
- minePendingTransactions
  - The "mining" of a block containing the list of pending transaction. "Mining" will reward a user with Buff-CUoin
- getBalanceOfAddress
  - Computes the balance of a given user

# Block Object
**Private Data Members**
- long long nonce
  - Arbitrary number used for authentication
- transactions - vector of Transaction
  - Contains all the completed transactions
- string previousHash
  - Stores the previous hash block 
- string hash
  - Stores the hash of the current block 
- time_t timestamp
  - Stores the time upon creation

**Member Functions**
- calculateHash
  - Converts all the variables in the Block class as a single string and computes the hashcode using sha256  
- mineBlock
  - Proof of work component that generates a hashcode until the first #difficulty characters equals 0   

# Transaction Object
**Private Data Members**
- string sender
  - Address of the person making the transaction    
- string receiver
  - Address of the person receiving the transaction
- int amount
  - The amount of Buff-Cuoin to be transferred   

**Member Functions**
- toString
  - Converts the Transaction data members as a single string

# How to run
> 1. In the project folder, navigate to build
> 2. Run cmake .. and make
> 3. Run ./run_app_1

# Contributor
**Jason Lee**
