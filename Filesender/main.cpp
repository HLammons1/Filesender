//#include "ConvertToBlocks.h"
//#include "Filereader.h"
//#include <iostream>
//#include <memory>
//#include <string>
//
//int main() {
//    Filereader reader;
//    std::string fileText = reader.ReturnFileString("example.txt");
//    std::cout << "Original text:\n" << fileText << "\n\n";
//
//    ConvertToBlocks converter;
//
//    std::unique_ptr<std::string> textPtr = std::make_unique<std::string>(fileText);
//    std::vector<std::unique_ptr<unsigned char[]>> blocks = converter.TextToCharBlocks(std::move(textPtr));
//
//    std::cout << "Converted Blocks:\n";
//    for (const auto& block : blocks) {
//        for (int i = 0; i < 16; ++i) {
//            std::cout << block[i];
//        }
//        std::cout << "\n";
//    }
//
//    return 0;
//}
