#ifndef _SENDMANAGER_H
#define _SENDMANAGER_H

#include <memory>
#include "IFilereader.h"
#include "IConvertToBlocks.h"
#include "ISendFile.h"
#include "AES.h"


class SendManager
{
private:
	std::unique_ptr<IFilereader> fileReader;
	std::unique_ptr<IConvertToBlocks> converter;
	std::unique_ptr<ISendFile> sendFile;
public:
	SendManager(std::unique_ptr<IFilereader> fr, std::unique_ptr<IConvertToBlocks> cb, std::unique_ptr<ISendFile> sf)
		: fileReader(std::move(fr)), converter(std::move(cb)), sendFile(std::move(sf)) {}
	bool ManageSend(std::string);


};

#endif