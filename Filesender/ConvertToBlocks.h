#ifndef _CONVERTTOBLOCKS_H
#define _CONVERTTOBLOCKS_H

#include <string>
#include <memory>
#include <vector>
#include "IConvertToBlocks.h"

class ConvertToBlocks : IConvertToBlocks {
private:
	int numBlocks = 0;
	int numBytes = 0;
public:
	std::vector<std::unique_ptr<unsigned char[]>> TextToCharBlocks(std::unique_ptr<std::string> text);
	std::unique_ptr<std::string> TextToMultipleOf16(std::unique_ptr<std::string> text);
	void DetermineArraySize(std::unique_ptr<std::string> text);
	int GetNumBlocks();
};

#endif 