/*
 *  @author Thomas Cassimon
 *  @date   08/09/2022.
 */

#include "01_lists_iterators/name_generation.hpp"

#include <cstdlib>  // srand, rand

// You can write this helper function and use it in the functions below
std::string generate_random_name(std::uint64_t seed) {
    // TODO: Implement This!
    srand(seed);

    char letters[] = "abcdefghijklmnopqrstuvwxyz";

    std::string name;
    for (size_t i = 0; i < 10; i++) name += letters[rand() % 26];

    return name;
}

std::vector<std::string> fill_vector(std::size_t n_names, std::uint64_t seed) {
    // TODO: Implement This!
    std::vector<std::string> names;
    for (size_t i = 0; i < n_names; i++) names.push_back(generate_random_name(seed));
    return names;
}

std::list<std::string> fill_list(std::size_t n_names, std::uint64_t seed) {
    // TODO: Implement This!
    std::list<std::string> names;
    for (size_t i = 0; i < n_names; i++) names.push_back(generate_random_name(seed));
    return names;
}