cmake_minimum_required(VERSION 3.21)
project(07_project)

set(CMAKE_CXX_STANDARD 23)

# add_library(ProjectLib STATIC 
#     "src/07_project/turtle.cpp"
# )

# target_include_directories(ProjectLib PRIVATE "include/")

add_executable(TestSuite
    "test/main.cpp"
    "test/l-system.cpp"
)

target_include_directories(TestSuite PRIVATE "include/")

# target_link_libraries(TestSuite PRIVATE ProjectLib)

# add_executable(System
#     "test/L-system.cpp"
# )

# target_include_directories(System PRIVATE "include/")
# target_link_libraries(System PRIVATE ProjectLib)

