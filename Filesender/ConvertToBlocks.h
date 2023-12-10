#ifndef _CONVERTTOBLOCKS_H
#define _CONVERTTOBLOCKS_H

#include <string>
#include <memory>
#include <vector>
#include "IConvertToBlocks.h"

class ConvertToBlocks : public IConvertToBlocks {
private:
	int numBlocks = 0;
	int numBytes = 0;
public:
	std::vector<std::unique_ptr<unsigned char[]>> TextToCharBlocks(std::unique_ptr<std::string> text) override;
	std::unique_ptr<std::string> TextToMultipleOf16(std::unique_ptr<std::string> text) override;
	void DetermineArraySize(std::unique_ptr<std::string> text);
	int GetNumBlocks();
};

#endif 