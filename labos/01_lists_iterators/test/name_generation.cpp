/*
 *  @author Thomas Cassimon
 *  @date   08/09/2022.
 */

#include "01_lists_iterators/name_generation.hpp"

#include <catch2/catch.hpp>
#include <iostream>  // For std::cout and std::endl

// TODO: Define a test case that checks that uses fill_vector() to generate some names,
//  and checks that the correct names are returned and that the correct amount of names is returned

TEST_CASE("fill_vector, Same Seed Yields Same Names", "[vector]") {
    // TODO: Fill in this test case
    const uint8_t n_names = 5;
    const uint16_t seed = 100;

    std::vector<std::string> names = fill_vector(n_names, seed);

    std::cout << "========= Begin vector =========" << std::endl;
    for (std::string name : names) std::cout << name << ", ";
    std::cout << "\n========= End vector =========" << std::endl;
}

// TODO: Define a test case that checks that uses fill_list() to generate some names,
//  and checks that the correct names are returned and that the correct amount of names is returned

TEST_CASE("fill_list, Same Seed Yields Same Names", "[list]") {
    // TODO: Fill in this test case
    const uint8_t n_names = 5;
    const uint16_t seed = 100;

    std::list<std::string> names = fill_list(n_names, seed);

    std::cout << "========= Begin list =========" << std::endl;
    for (std::string name : names) std::cout << name << ", ";
    std::cout << "\n========= End list =========" << std::endl;
}
