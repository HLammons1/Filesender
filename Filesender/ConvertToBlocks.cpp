#include "ConvertToBlocks.h"

std::vector<std::unique_ptr<unsigned char[]>> ConvertToBlocks::TextToCharBlocks(std::unique_ptr<std::string> text) {
	DetermineArraySize(std::move(text));
	std::vector<std::unique_ptr<unsigned char[]>> blocks(numBlocks);

	int bytesRemaining = numBytes;
	int blocksRemaining = numBlocks;
	while (bytesRemaining >= 16) { 
		std::string sixteenBytes = text->substr(0, 16);
		unsigned char* charArr = reinterpret_cast<unsigned char*>(&sixteenBytes[0]);
		text->erase(0, 16);
		blocks[numBlocks - blocksRemaining] = std::make_unique<unsigned char[]>(16);
		std::copy(charArr, charArr + 16, blocks[numBlocks - blocksRemaining].get());
		bytesRemaining -= 16;
		blocksRemaining--;
	}

	
	int padding = bytesRemaining % 16;
	//add bytesRemain

	return blocks;
}

void ConvertToBlocks::DetermineArraySize(std::unique_ptr<std::string> text)
{
	numBytes = text->size();
	numBlocks = numBytes % 16 == 0 ? numBytes / 16 : numBytes / 16 + 1;
	return;
}

int ConvertToBlocks::GetNumBlocks()
{
	return numBlocks;
}
