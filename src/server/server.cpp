#include "server.hpp"

namespace server {

auto Server::server_async_accept() -> void {
    _socket.emplace(_context);

    _acceptor.async_accept(_socket.value(), 
    [&](boost::system::error_code error) {
        std::make_shared<Session>(std::move(_socket.value()))->start_session();
        server_async_accept();
    });
}

} // namespace server