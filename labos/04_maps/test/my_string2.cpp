/*
 *  @author Thomas Cassimon
 *  @date   15/11/2022.
 */

#include "04_maps/my_string2.hpp"

#include <catch2/catch.hpp>
#include <unordered_map>

// TODO: Implement Unit Tests for MyString2!
TEST_CASE("Hash Function for MyString2", "[MyString2][Hash]") {
    std::unordered_map<MyString2, int> map;
    MyString2 key1 = {"Hello"};
    MyString2 key2 = {"World"};
    MyString2 key3 = {"HelloWorld"};
    MyString2 key4 = {"H"};

    map[key1] = 1;
    map[key2] = 2;
    map[key3] = 3;
    map[key4] = 4;

    REQUIRE(map[key1] == 1);
    REQUIRE(map[key2] == 2);
    REQUIRE(map[key3] == 3);
    REQUIRE(map[key4] == 4);

    // Check that all strings produce the same hash (42)
    REQUIRE(std::hash<MyString2>{}(key1) == 42);
    REQUIRE(std::hash<MyString2>{}(key2) == 42);
    REQUIRE(std::hash<MyString2>{}(key3) == 42);
    REQUIRE(std::hash<MyString2>{}(key4) == 42);
}
