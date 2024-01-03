#include "server.hpp"

int main() {
    boost::asio::io_context context;

    server::Server serv(context, 8080);
    std::cout << "Server was started at port 8080" << std::endl;
    serv.server_async_accept();
    context.run();
    return 0;
}