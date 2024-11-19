/*
 *  @author Thomas Cassimon
 *  @date   15/11/2022.
 */

#pragma once
#include <string>

// TODO: Implement MyString1 Struct
struct MyString1 {
    std::string value;

    MyString1() = default;
};

bool operator==(const MyString1& lhs, const MyString1& rhs);

namespace std {
template <>
struct hash<MyString1> {
    std::size_t operator()(const MyString1& key) const;
};
}  // namespace std
