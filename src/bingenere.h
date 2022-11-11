#ifndef BINGENERE_H
#define BINGENERE_H

#include <stdint.h>
#include <stddef.h>
#include <malloc.h>

uint8_t* bingenere_encrypt(uint8_t* data, uint8_t* key);
uint8_t* bingenere_decrypt(uint8_t* data, uint8_t* key);

#endif