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

    std::string names[] = {"Emma", "Liam", "Olivia", "Noah", "Ava", "Elijah", "Sophia", "Lucas", "Isabella", "Mason",
                           "Mia", "Ethan", "Amelia", "James", "Harper", "Benjamin", "Evelyn", "Alexander", "Abigail", "Henry",
                           "Ella", "Sebastian", "Avery", "Jackson", "Scarlett", "Aiden", "Grace", "Matthew", "Chloe", "David"};

    return names[rand() % 30];
}

std::vector<std::string> fill_vector(std::size_t n_names, std::uint64_t seed) {
    // TODO: Implement This!
    std::vector<std::string> names;
    for (size_t i = 0; i < n_names; i++) names.push_back(generate_random_name(seed + i));
    return names;
}

std::list<std::string> fill_list(std::size_t n_names, std::uint64_t seed) {
    // TODO: Implement This!
    std::list<std::string> names;
    for (size_t i = 0; i < n_names; i++) names.push_back(generate_random_name(seed + i));
    return names;
}