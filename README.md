# binary-vigenere
A simple C library for encrypting & decrypting data in a custom [Vigenère cipher](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher), suited for raw bytes. 

## Building
To include the library in your project, simply include the `src/bingenere.h` into your C code and add the `src/bingenere.c` at the complication with your code files together.

## Usage

### Encrypting
```c
uint8_t* bingenere_encrypt(uint8_t* data, uint8_t* key);
```
Encrypt a data byte array (an array of unsigned chars) with a key (also a byte array) using the binary Vigenère cipher.

**Arguments:**
- `uint8_t* data`: an array of unsigned chars, containing the data for encryption.
- `uint8_t* key`: an array of unsigned chars, containing the key for encryption.

**Returns:**
an array of unsigned chars, containing the encrypted bytes.

### Decrypting
```c
uint8_t* bingenere_decrypt(uint8_t* data, uint8_t* key);
```
Decrypt a data byte array (an array of unsigned chars) with a key (also a byte array) using the binary Vigenère cipher.

**Arguments:**
- `uint8_t* data`: an array of unsigned chars, containing the data for decryption.
- `uint8_t* key`: an array of unsigned chars, containing the key for decryption.

**Returns:**
an array of unsigned chars, containing the decrypted bytes.

## Testing
To test the library, simply run:
```sh
make tests
```
That will compile and run all of the implemented tests.

## Contributing
As with all my projects, contributions are highly appreciated!