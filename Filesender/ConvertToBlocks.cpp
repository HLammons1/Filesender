#include "ConvertToBlocks.h"

std::vector<std::unique_ptr<unsigned char[]>> ConvertToBlocks::TextToCharBlocks(std::unique_ptr<std::string> text) {
	std::unique_ptr<std::string> tempText = std::make_unique<std::string>(*text);
	DetermineArraySize(std::move(text));
	std::vector<std::unique_ptr<unsigned char[]>> blocks(numBlocks);

	int bytesRemaining = numBytes;
	int blocksRemaining = numBlocks;
	while (bytesRemaining >= 16) { 
		std::string sixteenBytes = tempText->substr(0, 16);
		unsigned char* charArr = reinterpret_cast<unsigned char*>(&sixteenBytes[0]);
		tempText->erase(0, 16);
		blocks[numBlocks - blocksRemaining] = std::make_unique<unsigned char[]>(16);
		std::copy(charArr, charArr + 16, blocks[numBlocks - blocksRemaining].get());
		bytesRemaining -= 16;
		blocksRemaining--;
	}

	if (bytesRemaining > 0) {
		std::string lastBlock = tempText->substr(0, bytesRemaining);
		lastBlock.append(16 - bytesRemaining, '\0');
		unsigned char* lastCharArr = reinterpret_cast<unsigned char*>(&lastBlock[0]);
		blocks[numBlocks - blocksRemaining] = std::make_unique<unsigned char[]>(16);
		std::copy(lastCharArr, lastCharArr + 16, blocks[numBlocks - blocksRemaining].get());
	}

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

std::unique_ptr<std::string> ConvertToBlocks::TextToMultipleOf16(std::unique_ptr<std::string> text) {
	int paddingSize = 16 - text->size() % 16;
	if (paddingSize != 16) {
		text->append(paddingSize, '\0');
	}
	return text;
}
