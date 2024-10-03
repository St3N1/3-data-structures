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
    const uint8_t N_NAMES = 5;
    const uint16_t SEED = 100;
    const std::vector<std::string> NAMES_CHECK = {"Ella", "Grace", "Grace", "Henry", "Benjamin"};

    std::vector<std::string> names = fill_vector(N_NAMES, SEED);

    std::cout << "========= Begin vector =========" << std::endl;
    for (std::string name : names) std::cout << name << ", ";
    std::cout << "\n========= End vector =========" << std::endl;

    CHECK(names == NAMES_CHECK);
    CHECK(names.size() == N_NAMES);
}

// TODO: Define a test case that checks that uses fill_list() to generate some names,
//  and checks that the correct names are returned and that the correct amount of names is returned

TEST_CASE("fill_list, Same Seed Yields Same Names", "[list]") {
    // TODO: Fill in this test case
    const uint8_t N_NAMES = 5;
    const uint16_t SEED = 200;
    const std::list<std::string> NAMES_CHECK = {"James", "Mia", "Amelia", "Amelia", "Chloe"};

    std::list<std::string> names = fill_list(N_NAMES, SEED);

    std::cout << "========= Begin list =========" << std::endl;
    for (std::string name : names) std::cout << name << ", ";
    std::cout << "\n========= End list =========" << std::endl;

    CHECK(names == NAMES_CHECK);
    CHECK(names.size() == N_NAMES);
}
