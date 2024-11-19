/*
 *  @author Thomas Cassimon
 *  @date   15/11/2022.
 */

#include "04_maps/my_string1.hpp"

#include <catch2/catch.hpp>
#include <unordered_map>

// TODO: Implement Unit Tests for MyString1!
TEST_CASE("Hash Function for MyString1", "[MyString1][Hash]") {
    std::unordered_map<MyString1, int> map;
    MyString1 key1 = {"Hello"};
    MyString1 key2 = {"World"};
    MyString1 key3 = {"HelloWorld"};
    MyString1 key4 = {"H"};

    map[key1] = 1234;
    map[key2] = 2;
    map[key3] = 3;
    map[key4] = 4;

    REQUIRE(map[key1] == 1234);
    REQUIRE(map[key2] == 2);
    REQUIRE(map[key3] == 3);
    REQUIRE(map[key4] == 4);

    // Check that different strings produce different hashes
    REQUIRE(std::hash<MyString1>{}(key1) != std::hash<MyString1>{}(key2));
    REQUIRE(std::hash<MyString1>{}(key1) != std::hash<MyString1>{}(key3));
    REQUIRE(std::hash<MyString1>{}(key1) != std::hash<MyString1>{}(key4));
}
