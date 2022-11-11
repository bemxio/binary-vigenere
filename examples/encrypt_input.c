#include "../src/bingenere.h"

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>

#define MAX_LENGTH 100 // just for example purposes, can be changed

int main() {
    uint8_t input[MAX_LENGTH] = {0};
    uint8_t key[MAX_LENGTH] = {0};

    printf("Enter the data: ");
    fgets(input, 100, stdin);

    printf("Enter the key: ");
    fgets(key, 100, stdin);
    
    // delete the newline character from the input & key
    input[strlen(input) - 1] = '\0';
    key[strlen(key) - 1] = '\0';

    uint8_t* output = bingenere_encrypt(input, key);
    
    printf("\nHere's the encrypted data, represented in a hexadecimal format!\n");

    for (size_t i = 0; i < MAX_LENGTH; i++) {
        if (output[i] == 0x00 && output[i - 1] == 0x00) {
            break; // this prevents the loop from printing the unchanged zeros
        }
        
        printf("%02X ", output[i]);
    }
    
    return 0;
}