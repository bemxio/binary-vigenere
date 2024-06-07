#include "../bingenere/bingenere.h"

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>

#define MAX_LENGTH 127

int main() {
    // get the input and key from the user
    char input[MAX_LENGTH] = {0};
    char key[MAX_LENGTH] = {0};

    printf("Enter the data: ");
    fgets(input, MAX_LENGTH, stdin);

    printf("Enter the key: ");
    fgets(key, MAX_LENGTH, stdin);

    // remove the newline character from the input and key
    input[strlen(input) - 1] = '\0';
    key[strlen(key) - 1] = '\0';

    // decrypt the input using the key
    uint8_t* output = bingenere_decrypt((uint8_t*)input, (uint8_t*)key);

    // print the decrypted data in hex and string format
    printf("\nHere's the decrypted data, represented in a hexadecimal format!\n");

    for (size_t i = 0; i < MAX_LENGTH; i++) {
        if (output[i] == 0x00 && output[i - 1] == 0x00) {
            break; // this prevents the loop from printing the unchanged zeros
        }

        printf("%02X ", output[i]);
    }

    printf("\nAnd here's the decrypted data, represented as a string!\n");
    printf("%s\n", output);

    return 0;
}