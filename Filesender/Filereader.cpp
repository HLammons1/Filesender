#include "Filereader.h"



    std::string Filereader::ReturnFileString(std::string path)
    {
        std::stringstream ss;
        std::fstream myFile(path, std::ios::in);

        if (!myFile.is_open()) {
            throw std::runtime_error("Unable to open file: " + path);
        }

        std::string line;
        while (std::getline(myFile, line)) {
            ss << line << "\n";
        }

        return ss.str();
    }

