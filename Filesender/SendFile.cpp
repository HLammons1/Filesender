#include "SendFile.h"

void SendFile::Send(const std::vector<unsigned char> data) {
	boost::asio::io_service io_service;
	boost::asio::ip::tcp::resolver resolver(io_service);
	boost::asio::ip::tcp::resolver::query query(server, port);
	boost::asio::ip::tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

	boost::asio::ip::tcp::socket socket(io_service);
	boost::asio::connect(socket, endpoint_iterator);

	boost::asio::write(socket, boost::asio::buffer(data));

	socket.close();
}

