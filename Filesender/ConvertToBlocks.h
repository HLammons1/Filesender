#ifndef _CONVERTTOBLOCKS_H
#define _CONVERTTOBLOCKS_H

#include <string>
#include <memory>
#include <vector>

class ConvertToBlocks
{
private:
	int numBlocks = 0;
	int numBytes = 0;
public:
	std::unique_ptr<unsigned char> TextToCharBlocks(std::unique_ptr<std::string> text);
	void DetermineArraySize(std::unique_ptr<std::string> text);
	int GetNumBlocks();
};

#endif 