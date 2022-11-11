#include "bingenere.h"

size_t _get_data_length(uint8_t* data) {
    size_t length = 0;

    while (*data) {
        length++;
        data++;
    }

    return length;
}

uint8_t* bingenere_encrypt(uint8_t* data, uint8_t* key) {
    const size_t data_size = _get_data_length(data);
    const size_t key_size = _get_data_length(key);
    
    uint8_t* result = (uint8_t*)calloc(data_size, 1);

    for (size_t index = 0; index < data_size; index++) {
        result[index] = (data[index] + key[index % key_size]) % 256;
    }

    return result;
}

uint8_t* bingenere_decrypt(uint8_t* data, uint8_t* key) {
    const size_t data_size = _get_data_length(data);
    const size_t key_size = _get_data_length(key);
    
    uint8_t* result = (uint8_t*)calloc(data_size, 1);

    for (size_t index = 0; index < data_size; index++) {
        result[index] = (data[index] - key[index % key_size] + 256) % 256;
    }

    return result;
}