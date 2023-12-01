#include "AES.h"
#include <iostream>
#include <vector>
#include <memory>
#include <cstring>
#include "ConvertToBlocks.h"
#include "Filereader.h"
#include "SendFile.h"


//int main() {
//    Filereader reader;
//    ConvertToBlocks converter;
//
//    std::string fileText = reader.ReturnFileString("example.txt");
//    std::cout << "Original text:\n" << fileText << "\n\n";
//
//    std::unique_ptr<std::string> textPtr = std::make_unique<std::string>(fileText);
//    std::vector<std::unique_ptr<unsigned char[]>> blocks = converter.TextToCharBlocks(std::move(textPtr));
//
//    std::vector<unsigned char> key = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
//                                       0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
//                                       0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
//                                       0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F };
//
//    std::vector<unsigned char> iv = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
//                                        0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F };
//
//    AES aes(AESKeyLength::AES_256);
//
//    std::vector<unsigned char> encryptedData;
//    std::vector<unsigned char> decryptedData;
//
//    for (const auto& block : blocks) {
//        std::vector<unsigned char> blockData(block.get(), block.get() + 16);
//        auto encryptedBlock = aes.EncryptCBC(blockData, key, iv);
//        encryptedData.insert(encryptedData.end(), encryptedBlock.begin(), encryptedBlock.end());
//
//        auto decryptedBlock = aes.DecryptCBC(encryptedBlock, key, iv);
//        decryptedData.insert(decryptedData.end(), decryptedBlock.begin(), decryptedBlock.end());
//    }
//
//    std::string result(decryptedData.begin(), decryptedData.end());
//
//    std::cout << "Encrypted: ";
//    aes.printHexVector(encryptedData);
//    std::cout << "\nDecrypted: " << result << "\n";
//
//    return 0;
//}



int main() {
    Filereader reader;
    ConvertToBlocks converter;

    std::string fileText = reader.ReturnFileString("example.txt");
    std::cout << "Original text:\n" << fileText << "\n\n";

    std::unique_ptr<std::string> textPtr = std::make_unique<std::string>(fileText);
    std::unique_ptr<std::string> paddedText = converter.TextToMultipleOf16(std::move(textPtr));

    std::vector<unsigned char> key = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                                      0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
                                      0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
                                      0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F };
        
    std::vector<unsigned char> iv = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                                     0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F };

    std::vector<unsigned char> data(paddedText->begin(), paddedText->end());

    AES aes(AESKeyLength::AES_256);

    std::vector<unsigned char> encryptedData = aes.EncryptCBC(data, key, iv);
    std::vector<unsigned char> decryptedData = aes.DecryptCBC(encryptedData, key, iv);
    std::string result(decryptedData.begin(), decryptedData.end());

    std::cout << "Original (padded): ";
    aes.printHexVector(data);
    std::cout << "\nEncrypted: ";
    aes.printHexVector(encryptedData);
    std::cout << "\nDecrypted: ";
    aes.printHexVector(decryptedData);
    std::cout << "\nString: " << result;

    //SendFile send("127.0.0.1", "8080");
    //send.Send(result);

    return 0;
}
