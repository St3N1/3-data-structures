cmake_minimum_required(VERSION 3.21)
project(07_project)

set(CMAKE_CXX_STANDARD 23)

add_library(ProjectLib STATIC 
"src/07_project/l-system_interpreter.cpp"
"src/07_project/production_hash.cpp"
"src/07_project/production.cpp"
"src/07_project/valid_production.cpp"
)

target_include_directories(ProjectLib PRIVATE "include/")

add_executable(TestSuite
    "test/main.cpp"
    "test/l-system.cpp"
)

target_include_directories(TestSuite PRIVATE "include/")
target_link_libraries(TestSuite PRIVATE ProjectLib)

add_executable(L-system
    "src/07_project/main.cpp"
)

target_include_directories(L-system PRIVATE "include/")
target_link_libraries(L-system PRIVATE ProjectLib)

