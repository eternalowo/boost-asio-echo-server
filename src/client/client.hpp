#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <string>

#include <boost/asio.hpp>

using boost::asio::ip::tcp;

namespace client {

const std::string DEFAULT_IP   = "127.0.0.1";
const std::string DEFAULT_PORT = "8080";
    
class Client {
public:
    Client(boost::asio::io_context& context, tcp::socket&& socket)
        : _context(context), _resolver(context), _socket(std::move(socket)) {}
    
    auto client_connect(std::string_view ip, std::string_view port) -> void;
    auto client_send(const std::string& message) -> void;

private:
    boost::asio::io_context& _context;
    tcp::resolver _resolver;
    tcp::socket _socket;
};

} // namespace client

#endif