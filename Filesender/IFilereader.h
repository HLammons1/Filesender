#ifndef _IFILEREADER_H
#define _IFILEREADER_H

#include <string>


class IFilereader {
public:
	virtual ~IFilereader() = default;
	virtual std::string ReturnFileString(std::string path) = 0;
};

#endif
