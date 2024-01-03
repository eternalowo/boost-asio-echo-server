#include "client.hpp"

namespace client {

auto Client::client_connect(std::string_view ip, std::string_view port) -> void {
    tcp::resolver::results_type endpoints = _resolver.resolve(ip, port);
    boost::asio::connect(_socket, endpoints);
}

auto Client::client_send(const std::string& message) -> void {
    boost::asio::write(_socket, boost::asio::buffer(message));
}

} // namespace client