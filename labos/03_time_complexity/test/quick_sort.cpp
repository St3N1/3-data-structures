/*
 * @author idlab
 * @date 16/08/2022
 */

#include <03_time_complexity/quick_sort.hpp>
#include <catch2/catch.hpp>

TEST_CASE("quick_sort, sorted array", "[quick_sort][sorted]") {
    // TODO: Implement a unit test that calls quick sort on a sorted array and checks the result!
    std::vector<int> sorted = {1, 2, 4, 6, 8, 9};

    REQUIRE(quick_sort(sorted) == sorted);
}

TEST_CASE("quick_sort, random array", "[quick_sort][random]") {
    // TODO: Implement a unit test that calls quick sort on a random array and checks the result!
    std::vector<int> vector = {6, 2, 8, 9, 4, 1};
    std::vector<int> sorted = {1, 2, 4, 6, 8, 9};

    REQUIRE(quick_sort(vector) == sorted);
}

TEST_CASE("quick_sort, reversed array", "[quick_sort][reversed]") {
    // TODO: Implement a unit test that calls quick sort on a reversed array and checks the result!
    std::vector<int> vector = {9, 8, 6, 4, 2, 1};
    std::vector<int> sorted = {1, 2, 4, 6, 8, 9};

    REQUIRE(quick_sort(vector) == sorted);
}