#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <optional>

#include <boost/asio.hpp>

#include "session.hpp"

using boost::asio::ip::tcp;

namespace server {

class Server {
public:
    Server(boost::asio::io_context& context, std::uint16_t port)
        : _context(context), _acceptor(context, tcp::endpoint(tcp::v4(), port)) {}
        
    auto server_async_accept() -> void;

private:
    boost::asio::io_context& _context;
    tcp::acceptor _acceptor;
    std::optional<tcp::socket> _socket;
};

} // namespace server

#endif