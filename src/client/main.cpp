#include <iostream>

#include "client.hpp"

int main() {
    boost::asio::io_context context;
    std::string message;
    auto clnt = client::Client(context, tcp::socket(context));

    clnt.client_connect(client::DEFAULT_IP, client::DEFAULT_PORT);
    
    std::cout << "Enter your message for server: ";
    std::getline(std::cin, message);
    clnt.client_send(message);
    return 0;
}