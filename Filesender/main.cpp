#include "Filereader.h"


int main() {
	Filereader reader;
	std::string fileText = reader.ReturnFileString("example.txt");
	std::cout << fileText;

	return 0;
}