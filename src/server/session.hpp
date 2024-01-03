#ifndef SESSION_HPP_
#define SESSION_HPP_

#include <iostream>

#include <boost/asio.hpp>

using boost::asio::ip::tcp;

namespace server {

class Session : public std::enable_shared_from_this<Session> {
public:
    Session(tcp::socket&& socket) : _socket(std::move(socket)) {}
    
    auto start_session() -> void;

private:
    tcp::socket _socket;
    boost::asio::streambuf _stream_buffer;
};

} // namespace server

#endif