cmake_minimum_required(VERSION 3.8)

project(EchoClient-Server)

find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

set(SERVER_HDR 
    src/server/server.hpp
    src/server/session.hpp
)

set(SERVER_SRC 
    src/server/server.cpp
    src/server/session.cpp
    src/server/main.cpp
)

set(CLIENT_HDR 
    src/client/client.hpp
)

set(CLIENT_SRC 
    src/client/client.cpp
    src/client/main.cpp
)

add_executable(Server ${SERVER_HDR} ${SERVER_SRC})
add_executable(Client ${CLIENT_HDR} ${CLIENT_SRC})

target_link_libraries(Server PRIVATE ${Boost_LIBRARIES})
target_link_libraries(Client PRIVATE ${Boost_LIBRARIES})

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET Server PROPERTY CXX_STANDARD 20)
    set_property(TARGET Client PROPERTY CXX_STANDARD 20)
endif()