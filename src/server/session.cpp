#include "session.hpp"

namespace server {

auto Session::start_session() -> void {
    boost::asio::async_read_until(_socket, _stream_buffer, '\n',
    [self = shared_from_this()](boost::system::error_code error, std::size_t transferred_bytes) {
        std::cout << std::istream(&self->_stream_buffer).rdbuf() << std::endl;
    });
}

} // namespace server