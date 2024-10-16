cmake_minimum_required(VERSION 3.21)
project(02_queues_stacks)

set(CMAKE_CXX_STANDARD 17)

# TODO: Create a STATIC library called "PacketLib"
#   Make sure to add all the relevant source files to your library!
add_library(PacketLib STATIC
    src/02_queues_stacks/packet.cpp
    src/02_queues_stacks/router.cpp
)

target_include_directories(PacketLib PRIVATE "include/")

# TODO: Create an executable called "TestSuite"
#   Make sure to add all the relevant source files to the executable
add_executable(TestSuite
    test/main.cpp
    test/packet.cpp
    test/router.cpp
)
target_include_directories(TestSuite PRIVATE "include/")

target_link_libraries(TestSuite PRIVATE PacketLib)
