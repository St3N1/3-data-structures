cmake_minimum_required(VERSION 3.21)
project(04_maps)

set(CMAKE_CXX_STANDARD 17)

# TODO: Create a STATIC library called "MapLib"
add_library(MapLib STATIC 
    "src/04_maps/my_string1.cpp"
    "src/04_maps/my_string2.cpp"
)

target_include_directories(MapLib PRIVATE "include/")

# TODO: Create an executable called "TestSuite"
add_executable(TestSuite
    "test/main.cpp"
    "test/my_string1.cpp"
    "test/my_string2.cpp"
)

target_include_directories(TestSuite PRIVATE "include/")
target_link_libraries(TestSuite PRIVATE MapLib)

# TODO: Create an executable called "Measure"
add_executable(Measure
    "src/04_maps/measure.cpp"
)

target_include_directories(Measure PRIVATE "include/")
target_link_libraries(Measure PRIVATE MapLib)

