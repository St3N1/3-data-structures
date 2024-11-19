/*
 * @author idlab
 * @date 16/08/2022
 */

#include <03_time_complexity/insertion_sort.hpp>
#include <catch2/catch.hpp>
#include <iostream>

TEST_CASE("insertion_sort, sorted array", "[insertion_sort][sorted]") {
    // TODO: Implement a unit test that calls insertion sort on a sorted array and checks the result!
    std::vector<int> sorted = {1, 2, 4, 6, 8, 9};
    REQUIRE(insertion_sort(sorted) == sorted);
}

TEST_CASE("insertion_sort, random array", "[insertion_sort][random]") {
    // TODO: Implement a unit test that calls insertion sort on a random array and checks the result!
    std::vector<int> vector = {6, 2, 8, 9, 4, 1};
    std::vector<int> sorted = {1, 2, 4, 6, 8, 9};

    REQUIRE(insertion_sort(vector) == sorted);
}

TEST_CASE("insertion_sort, reversed array", "[insertion_sort][reversed]") {
    // TODO: Implement a unit test that calls insertion sort on a reversed array and checks the result!
    std::vector<int> vector = {9, 8, 6, 4, 2, 1};
    std::vector<int> sorted = {1, 2, 4, 6, 8, 9};

    REQUIRE(insertion_sort(vector) == sorted);
}