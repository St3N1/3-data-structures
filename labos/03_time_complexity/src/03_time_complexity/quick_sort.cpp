/*
 * @author idlab
 * @date 16/08/2022
 */

#include <03_time_complexity/quick_sort.hpp>

template <typename T>
std::size_t partition(std::vector<T>& vector, std::size_t low, std::size_t high) noexcept {
    T pivot = vector[high];
    std::size_t i = low;

    for (std::size_t j = low; j < high; j++) {
        if (vector[j] <= pivot) {
            std::swap(vector[i], vector[j]);
            i++;
        }
    }
    std::swap(vector[i], vector[high]);

    return i;
}

template <typename T>
void quick_sort_recursive(std::vector<T>& vector, std::size_t low, std::size_t high) noexcept {
    if (low < high) {
        std::size_t pivot = partition(vector, low, high);
        if (pivot > 0) quick_sort_recursive(vector, low, pivot - 1);
        quick_sort_recursive(vector, pivot + 1, high);
    }
}

template <typename T>
std::vector<T> quick_sort(const std::vector<T>& vector) noexcept {
    // TODO: Implement quick sort!
    std::vector<T> sorted = vector;
    quick_sort_recursive(sorted, 0, sorted.size());

    return std::vector<T>(sorted);
}

// Explicit template instantiation for int
template std::vector<int> quick_sort(const std::vector<int>&) noexcept;
