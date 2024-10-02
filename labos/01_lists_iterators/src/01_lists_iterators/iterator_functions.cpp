#include "01_lists_iterators/iterator_functions.hpp"

#include <algorithm>  // For std::for_each, std::copy_if
#include <iostream>   // For std::cout and std::endl
#include <list>       // For std::list
#include <vector>     // For std::vector

template <typename IteratorType>
void print_names(IteratorType begin, IteratorType end) {
    // TODO: Fill this in!
}

template <typename InputIteratorType, typename OutputIteratorType>
void filter_prefixed_names(
    InputIteratorType begin,
    InputIteratorType end,
    std::string prefix,
    OutputIteratorType output_begin) {
    // TODO: Fill this in!
}

template <typename IteratorType>
void print_reverse(IteratorType begin, IteratorType end) {
    // TODO: Fill this in!
}

// TODO: If you need explicit instantiations of the functions above, uncomment the code below!
// We will teach the templates course later in the course, so don't worry about this for now.
// If you want to learn more about templates, you can check out the following link:
// https://en.cppreference.com/w/cpp/language/templates

// template void print_names<std::vector<std::string>::iterator>(
//         std::vector<std::string>::iterator,
//         std::vector<std::string>::iterator
//);
// template void print_names<std::list<std::string>::iterator>(
//         std::list<std::string>::iterator,
//         std::list<std::string>::iterator
//);
//
// template void filter_prefixed_names<
//         std::vector<std::string>::iterator,
//         std::back_insert_iterator<std::vector<std::string>>
//>(
//         std::vector<std::string>::iterator,
//         std::vector<std::string>::iterator,
//         std::string,
//         std::back_insert_iterator<std::vector<std::string>>
//);
// template void filter_prefixed_names<
//         std::list<std::string>::iterator,
//         std::back_insert_iterator<std::list<std::string>>
//>(
//         std::list<std::string>::iterator,
//         std::list<std::string>::iterator,
//         std::string,
//         std::back_insert_iterator<std::list<std::string>>
//);
//
// template void print_reverse<std::vector<std::string>::iterator>(
//         std::vector<std::string>::iterator,
//         std::vector<std::string>::iterator
//);
// template void print_reverse<std::list<std::string>::iterator>(
//         std::list<std::string>::iterator,
//         std::list<std::string>::iterator
//);
