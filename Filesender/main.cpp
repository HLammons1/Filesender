#include "AES.h"
#include <iostream>
#include <vector>

int main() {
    // Example key and input
    std::vector<unsigned char> key = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                                      0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
                                      0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
                                      0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F};
    std::vector<unsigned char> data = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o',
                                       'r', 'l', 'd', '!', ' ', ' ', ' ', ' '}; // 16 bytes input

    // Create AES object
    AES aes(AESKeyLength::AES_256);

    // Encrypting in ECB mode
    std::vector<unsigned char> encryptedDataECB = aes.EncryptECB(data, key);
    std::vector<unsigned char> decryptedDataECB = aes.DecryptECB(encryptedDataECB, key);

    // Display the results
    std::cout << "Original: ";
    aes.printHexVector(data);
    std::cout << "\nEncrypted (ECB): ";
    aes.printHexVector(encryptedDataECB);
    std::cout << "\nDecrypted (ECB): ";
    aes.printHexVector(decryptedDataECB);
    std::cout << "\n";

    // Example Initialization Vector (IV) for CBC and CFB modes
    std::vector<unsigned char> iv = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                                     0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};

    // Encrypting in CBC mode
    std::vector<unsigned char> encryptedDataCBC = aes.EncryptCBC(data, key, iv);
    std::vector<unsigned char> decryptedDataCBC = aes.DecryptCBC(encryptedDataCBC, key, iv);

    // Display the results
    std::cout << "Encrypted (CBC): ";
    aes.printHexVector(encryptedDataCBC);
    std::cout << "\nDecrypted (CBC): ";
    aes.printHexVector(decryptedDataCBC);
    std::cout << "\n";

    // Encrypting in CFB mode
    std::vector<unsigned char> encryptedDataCFB = aes.EncryptCFB(data, key, iv);
    std::vector<unsigned char> decryptedDataCFB = aes.DecryptCFB(encryptedDataCFB, key, iv);

    // Display the results
    std::cout << "Encrypted (CFB): ";
    aes.printHexVector(encryptedDataCFB);
    std::cout << "\nDecrypted (CFB): ";
    aes.printHexVector(decryptedDataCFB);
    std::cout << "\n";

    return 0;
}
