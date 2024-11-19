/*
 * @author idlab
 * @date 16/08/2022
 */

#include <03_time_complexity/insertion_sort.hpp>

template <typename T>
std::vector<T> insertion_sort(const std::vector<T>& vector) noexcept {
    // TODO: Implement Insertion Sort!

    std::vector<T> sorted = vector;
    for (std::size_t dl = 1; dl < sorted.size(); dl++) {
        const T to_insert = sorted[dl];

        std::size_t i = dl;
        for (i = dl; (0 < i) && (to_insert < sorted[i - 1]); i--) sorted[i] = sorted[i - 1];

        sorted[i] = to_insert;
    }

    return std::vector<T>(sorted);
}

// Explicit template instantiation for int
template std::vector<int> insertion_sort(const std::vector<int>&) noexcept;