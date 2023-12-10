#ifndef _SENDFILE_H
#define _SENDFILE_H
#include <boost/asio.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include "ISendFile.h"

class SendFile : public ISendFile {
private:
	std::string server;
	std::string port;
public:
	SendFile(std::string server, std::string port) : server(std::move(server)), port(std::move(port)) {}
	void Send(const std::vector<std::vector<unsigned char>>& dataVec) override;
};

#endif