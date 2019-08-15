#include <stdio.h>
#include <time.h>
#include <string.h>


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


struct Block {
    // @TODO: Fill in the properites of a block
};

struct BlockChain {
    // @TODO: Fill in the properties of a block chain
};



unsigned long calculateHash(unsigned char * blockData, long currentTime, unsigned long previousHash) {
    // @TODO: Write a function to calculate the hash of a block.
    return 0;
}

void checkChain(struct Block *genesisBlock) {
    //@TODO: Write the code to check if the block chain is valid
    // Your code should look something like this:

    // if (chainValid == true) { printf("CHAIN IS VALID!\n"); }
    // else { printf("CHAIN INVALID"); }
}




int main() {
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
}


