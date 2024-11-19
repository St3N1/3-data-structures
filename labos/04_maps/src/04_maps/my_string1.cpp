/*
 *  @author Thomas Cassimon
 *  @date   15/11/2022.
 */
#include <04_maps/my_string1.hpp>
#include <cstdint>
#include <functional>

// TODO: Implement MyString1
bool operator==(const MyString1& lhs, const MyString1& rhs) {
    return lhs.value == rhs.value;
}

namespace std {
std::size_t hash<MyString1>::operator()(const MyString1& key) const {
    std::uint64_t H = 0;
    for (std::size_t i = 0; i < key.value.size(); ++i) {                              // iterate over each character in the string
        char C = key.value[i];                                                        // get the character
        std::size_t hash_index = i % 8;                                               // get the index of the character in the hash modulo 8, so it is between 0 and 7
        std::uint64_t shifted_c = static_cast<std::uint64_t>(C) << (hash_index * 8);  // shift the character to the left by the index times 8
        H = H ^ shifted_c;                                                            // XOR the shifted character with the hash
    }
    return static_cast<std::size_t>(H);
}
}  // namespace std
