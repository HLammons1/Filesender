#include "ConvertToBlocks.h"

std::unique_ptr<unsigned char> ConvertToBlocks::TextToCharBlocks(std::unique_ptr<std::string> text) {
	DetermineArraySize(std::move(text));
	std::vector<std::unique_ptr<unsigned char[]>> blocks(numBlocks);

	int bytesRemaining = numBytes;
	while (bytesRemaining >= 16) {
		
		//get sixteen bytes from the string
		//create a char array
		//remove the sixteen bytes
	}

	//switch (bytesRemaining % 16) {
	//case 3:
	//	h ^= bytes[2] << 16;
	//case 2:
	//	h ^= bytes[1] << 8;
	//case 1:
	//	h ^= bytes[0];
	//	h *= m;
	//}
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
