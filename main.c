#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>


// This hashing function is the djb2 hash function implementation.
// You do NOT have to use this hash function - if you find another hash
// function you like better, feel free to use it.
unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    // adding extra () to supress CLion warning messages about
    // using the "result of an assignment as a condition w/o parentheses"
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash;
}


typedef struct _Block {
    // @TODO: Fill in the properites of a block
    char *data;
    time_t currentTime;
    unsigned long previousHash;
    unsigned long myHash;
} Block;

typedef struct _BlockChain {
    // @TODO: Fill in the properties of a block chain
    Block blocks[200];

} BlockChain;



unsigned long calculateHash(unsigned char * blockData, long currentTime, unsigned long previousHash) {
    unsigned char dataToHash[] = {previousHash + currentTime + blockData};

    return hash(dataToHash);
}

void checkChain(Block *genesisBlock) {
    //@TODO: Write the code to check if the block chain is valid
    // Your code should look something like this:

    // if (chainValid == true) { printf("CHAIN IS VALID!\n"); }
    // else { printf("CHAIN INVALID"); }
}

void PrintBlockChain(BlockChain* blockChain){
    for(int i = 0; i < 200; i++){
        Block currentBlock = blockChain->blocks[i];
        if(currentBlock.data != NULL){
            printf("Block %d: %lu\n", i, currentBlock);
            printf("\tData = %s\n", currentBlock.data);
            printf("\tPrevious Hash: %lu\n", currentBlock.previousHash);
        }
        else return;
    }
}


int main() {



    BlockChain blockChain;
    Block rootBlock;
    time_t curTime;

    rootBlock.data = "Christian";
    rootBlock.previousHash = 0;
    rootBlock.currentTime = curTime;
    rootBlock.myHash = calculateHash(0, curTime, rootBlock.data);

    blockChain.blocks[0] = rootBlock;

    PrintBlockChain(&blockChain);


    int op;
    do {
        printf("Choose an option:\n");
        printf("\n 1. Add a new block to the chain");
        printf("\n 2. View the chain ");
        printf("\n 3. Check chain validity ");
        printf("\n 4. Search for a block ");
        printf("\n 5. Mine new block ");
        printf("\n 0. Exit");
        printf("\n\n Enter your choice:");
        scanf("%d", &op);

        switch (op) {
            case 1:
                break;
            case 2:
                PrintBlockChain(&blockChain);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;

            case 0:
                return 0;

            default:
                printf("Please Enter a valid number!");
                break;

        }
    } while (1);


}


/*
    // Example 1: How to generate a HASH of a string
    // ---------------------------

    unsigned char data[] = "Here is some nonsense";
    unsigned long hashValue = hash(data);
    printf("Data to hash: %s\n", data);
    printf("Hash value: %lu\n", hashValue);


    // Example 2: How to use C's time/date functions
    // ---------------------------


    // ---------------
    // Variables for detecting current time
    // ---------------
    time_t currentTime;
    char* formattedTime;


    // Get the current time (epoch time)
    // Epoch time = number of seconds that have passed since the year 1970.
    // See: https://www.epochconverter.com/
    currentTime = time(NULL);
    // Format epoch time into human readable time
    formattedTime = ctime(&currentTime);

    printf("Current formatted time is: %s", formattedTime);
    printf("Current epoch time is: %ld\n", currentTime);
    printf("----------\n");

    return 0;
*/


