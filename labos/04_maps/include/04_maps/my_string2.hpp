/*
 *  @author Thomas Cassimon
 *  @date   15/11/2022.
 */

#pragma once
#include <string>

// TODO: Implement MyString2 Struct
struct MyString2 {
    std::string value;

    MyString2() = default;
};

bool operator==(const MyString2& lhs, const MyString2& rhs);

namespace std {
template <>
struct hash<MyString2> {
    std::size_t operator()(const MyString2& key) const;
};
}  // namespace std
