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
    char* data;
    time_t currentTime;
    unsigned long previousHash;
    unsigned long myHash;
} Block;

typedef struct _BlockChain {
    Block blocks[200];

} BlockChain;



unsigned long calculateHash(unsigned char * blockData, long currentTime, unsigned long previousHash) {
    unsigned char dataToHash[500] = "";
    snprintf(dataToHash, sizeof(dataToHash), "%lu%ld%s", previousHash, currentTime, blockData);

    return hash(dataToHash);
}

unsigned long calculateHashWithXFactor(unsigned char * blockData, long currentTime, unsigned long previousHash, int xFactor) {
    unsigned char dataToHash[500] = "";
    snprintf(dataToHash, sizeof(dataToHash), "%lu%ld%s%d", previousHash, currentTime, blockData, xFactor);

    return hash(dataToHash);
}

void checkChain(BlockChain* blockChain) {
    for(int i = 0; i < 200; i++){
        Block currentBlock = blockChain->blocks[i];

        unsigned long hashedResult = calculateHash(currentBlock.data, currentBlock.currentTime, currentBlock.previousHash);

        if(currentBlock.data != NULL && hashedResult != currentBlock.myHash){

            printf("\nChain is not valid!\n");
            return;
        }
    }

    printf("\nChain is valid!\n");
}

void PrintBlockChain(BlockChain* blockChain){
    for(int i = 0; i < 200; i++){
        Block currentBlock = blockChain->blocks[i];
        if(currentBlock.data != NULL){
            printf("Block %d: %lu\n", i, currentBlock.myHash);
            printf("\tData = %s\n", currentBlock.data);
            printf("\tPrevious Hash: %lu\n", currentBlock.previousHash);
        }
        else return;
    }
}

void CreateAnotherBlock(BlockChain *blockChain, char data[]){
    char* name = NULL;
    name = strdup(data);
    for(int i = 0; i < 200; i++){
        Block currentBlock = blockChain->blocks[i];
        Block nextBlock;
        if(i < 199)
            nextBlock = blockChain->blocks[i+1];
        if(nextBlock.data == NULL){
            time_t currentTime = time(NULL);

            Block* newBlock = malloc(sizeof(Block));
            newBlock->data = name;
            newBlock->previousHash = currentBlock.myHash;
            newBlock->currentTime = currentTime;
            newBlock->myHash = calculateHash(name, currentTime, currentBlock.myHash);

            blockChain->blocks[i+1] = *newBlock;
            blockChain->blocks[i+2].data = NULL;

            break;
        }
    }

    return;
}

void MineNewBlock(BlockChain* blockChain){
    for(int i = 0; i < 200; i++){
        Block currentBlock = blockChain->blocks[i];

        if(currentBlock.data == NULL){
            time_t currentTime = time(NULL);

            int xFactor = 0;
            while(1){
                unsigned long hashedValue =
                        calculateHashWithXFactor("ChristianNJason", currentTime, currentBlock.myHash, xFactor);

                if(hashedValue % 13 == 0){
                    CreateAnotherBlock(blockChain, "Christian N Jason Assignment");
                    printf("\nFound a new block!\n");
                    return;
                }

                xFactor++;
            }
        }
    }
}

void SearchABlock(char* data, BlockChain* blockChain){
    Block* currentBlock = malloc(sizeof(Block));
    for(int i = 0; i < 200; i++){
        char* name = NULL;
        name = strdup(data);

        currentBlock = &blockChain->blocks[i];

        if(currentBlock->data != NULL && strcmp(currentBlock->data, name) == 0){
            printf("\nYeah, block is in the chain\n");
            return;
        }

        if(currentBlock->data == NULL) break;
    }

    printf("\nNope, the block with that data is not on the chain\n");
    return;
}



int main() {
    BlockChain* blockChain = malloc(sizeof(BlockChain));
    Block* rootBlock = malloc(sizeof(Block));
    time_t curTime = time(NULL);

    rootBlock->data = "Christian";
    rootBlock->previousHash = 0;
    rootBlock->currentTime = curTime;
    rootBlock->myHash = calculateHash(rootBlock->data , curTime,0);

    blockChain->blocks[0] = *rootBlock;
    //blockChain->blocks[1].data = NULL;


    int op;
    do {
        printf("-----------------\n");
        printf("Choose an option:\n");
        printf("1. Add a new block to the chain\n");
        printf("2. View the chain \n");
        printf("3. Check chain validity \n");
        printf("4. Search for a block \n");
        printf("5. Mine new block \n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &op);

        char word[25];
        switch (op) {
            case 1:
                printf("Please enter the data you want for the block: ");
                scanf("%s", word);
                CreateAnotherBlock(blockChain, word);
                break;
            case 2:
                PrintBlockChain(blockChain);
                break;
            case 3:
                checkChain(blockChain);
                break;
            case 4:
                printf("Please enter the data you want to search: ");
                scanf("%s", word);
                SearchABlock(word, blockChain);
                break;
            case 5:
                printf("\nMining in progress");
                MineNewBlock(blockChain);
                break;
            case 0:
                return 0;
            default:
                printf("Please Enter a valid number!");
                break;
        }
    } while (op != 0);

    return 0;
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


