#ifndef _ISENDFILE_H
#define _ISENDFILE_H

#include <string>

class ISendFile {
public:
	virtual ~ISendFile() = default;
	virtual void  Send(const std::vector<std::vector<unsigned char>>& dataVec) = 0;
};

#endif