#ifndef _ISENDFILE_H
#define _ISENDFILE_H

#include <string>

class ISendFile {
public:
	virtual void Send(const std::string& data) = 0;
};

#endif