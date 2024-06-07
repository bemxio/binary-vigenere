# binary-vigenere
A simple C library for encrypting and decrypting data in a custom [Vigenère cipher](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher), suited for raw bytes.

## Building
To include the library in your project, simply include the `src/bingenere.h` header into your C code and add the `src/bingenere.c` file when compiling together with your code. With GCC and a simple script, it would look something like this: `gcc /path/to/your_code.c /path/to/bingenere.c -o /path/to/executable`.

To build the examples in `src/examples/`, run:

```sh
make examples
```

That will generate the executables in the `build/` directory.

## Usage
### Encrypting
```c
uint8_t* bingenere_encrypt(uint8_t* data, uint8_t* key);
```
Encrypt a data byte array (an array of unsigned chars) with a key (also a byte array) using the binary Vigenère cipher.

**Arguments:**
- `uint8_t* data`: an array of unsigned chars, containing the data for encryption.
- `uint8_t* key`: an array of unsigned chars, containing the key for encryption.

**Returns:** an array of unsigned chars, containing the encrypted bytes.

### Decrypting
```c
uint8_t* bingenere_decrypt(uint8_t* data, uint8_t* key);
```
Decrypt a data byte array (an array of unsigned chars) with a key (also a byte array) using the binary Vigenère cipher.

**Arguments:**
- `uint8_t* data`: an array of unsigned chars, containing the data for decryption.
- `uint8_t* key`: an array of unsigned chars, containing the key for decryption.

**Returns:** an array of unsigned chars, containing the decrypted bytes.

## Testing
To test the library, simply run:

```sh
make tests
```

That will compile and run all of the implemented tests.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.