#ifndef _SENDFILE_H
#define _SENDFILE_H
#include <boost/asio.hpp>
#include <iostream>
#include <fstream>
#include <vector>

class SendFile {
private:
	std::string server;
	std::string port;
public:
	SendFile(std::string server, std::string port) : server(std::move(server)), port(std::move(port)) {}
	void Send(const std::string data);
};

#endif