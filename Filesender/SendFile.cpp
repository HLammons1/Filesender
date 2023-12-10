#include "SendFile.h"
#include <boost/asio.hpp>
#include <vector>

void SendFile::Send(const std::vector<std::vector<unsigned char>>& dataVec) {
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::resolver resolver(io_service);
    boost::asio::ip::tcp::resolver::query query(server, port);
    boost::asio::ip::tcp::socket socket(io_service);

    boost::system::error_code ec;
    boost::asio::connect(socket, resolver.resolve(query), ec);
    if (ec) {
        std::cerr << "Connect failed: " << ec.message() << std::endl;
        return;
    }

    for (const auto& data : dataVec) {
        size_t length = data.size();
        boost::asio::write(socket, boost::asio::buffer(&length, sizeof(size_t)), ec);
        if (ec) {
            std::cerr << "Send length failed: " << ec.message() << std::endl;
            break;
        }

        boost::asio::write(socket, boost::asio::buffer(data), ec);
        if (ec) {
            std::cerr << "Send data failed: " << ec.message() << std::endl;
            break;
        }
    }

    socket.close();
}
