#ifndef _ICONVERTTOBLOCKS_H
#define _ICONVERTTOBLOCKS_H

#include <string>
#include <vector>
#include <memory>


class IConvertToBlocks {
public:
	virtual ~IConvertToBlocks() = default;
	virtual std::vector<std::unique_ptr<unsigned char[]>> TextToCharBlocks(std::unique_ptr<std::string> text) = 0;
	virtual std::unique_ptr<std::string> TextToMultipleOf16(std::unique_ptr<std::string> text) = 0;
};

#endif
