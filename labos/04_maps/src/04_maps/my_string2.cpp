/*
 *  @author Thomas Cassimon
 *  @date   15/11/2022.
 */

#include <04_maps/my_string2.hpp>
#include <functional>

// TODO: Implement MyString2
bool operator==(const MyString2& lhs, const MyString2& rhs) {
    return lhs.value == rhs.value;
}

namespace std {
std::size_t hash<MyString2>::operator()(const MyString2& key) const {
    return 42;
}
}  // namespace std
