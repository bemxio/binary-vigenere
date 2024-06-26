#include "../bingenere/bingenere.h"
#include "Unity/src/unity.h"

#include <stdint.h>

void setUp() {}
void tearDown() {}

void test_encryption() {
    uint8_t* input_data = "Hello, cryptographers!";
    uint8_t* key = "TheCryptologistsSecret";

    uint8_t expected_data[] = {
        0x9C, 0xCD, 0xD1, 0xAF, 0xE1, 0xA5, 0x90, 0xD7, 0xE1, 0xE5, 0xDF, 0xDB,
        0xD8, 0xDA, 0xE6, 0xD4, 0xC3, 0xCD, 0xC8, 0xE4, 0xD8, 0x95, 0x00
    };
    uint8_t* actual_data = bingenere_encrypt(input_data, key);

    TEST_ASSERT_EQUAL_HEX8_ARRAY(expected_data, actual_data, sizeof expected_data);
}

void test_decryption() {
    uint8_t input_data[] = {
        0x9C, 0xCD, 0xD1, 0xAF, 0xE1, 0xA5, 0x90, 0xD7, 0xE1, 0xE5, 0xDF, 0xDB,
        0xD8, 0xDA, 0xE6, 0xD4, 0xC3, 0xCD, 0xC8, 0xE4, 0xD8, 0x95, 0x00
    };
    uint8_t* key = "TheCryptologistsSecret";

    uint8_t* expected_data = "Hello, cryptographers!";
    uint8_t* actual_data = bingenere_decrypt(input_data, key);

    TEST_ASSERT_EQUAL_HEX8_ARRAY(expected_data, actual_data, sizeof expected_data);
}

int main() {
    UNITY_BEGIN();

    RUN_TEST(test_encryption);
    RUN_TEST(test_decryption);

    return UNITY_END();
}