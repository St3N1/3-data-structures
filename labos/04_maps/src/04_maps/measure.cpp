/*
 *  @author Thomas Cassimon
 *  @date   15/11/2022.
 */

// TODO: Implement a program to perform task 5 from the assignment
#include <chrono>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "04_maps/my_string1.hpp"
#include "04_maps/my_string2.hpp"

int main() {
    // Define the sizes to benchmark
    std::vector<std::size_t> sizes = {10, 100, 1000, 10000};

    for (const auto& size : sizes) {
        // Initialize maps and key storage
        std::unordered_map<MyString1, int> map1;
        std::unordered_map<MyString2, int> map2;
        std::vector<MyString1> keys1;
        std::vector<MyString2> keys2;

        // Benchmark filling map1
        auto start_fill_map1 = std::chrono::high_resolution_clock::now();
        for (std::size_t i = 0; i < size; ++i) {
            MyString1 key1{std::to_string(i)};
            map1[key1] = static_cast<int>(i);
            keys1.push_back(key1);
        }
        auto end_fill_map1 = std::chrono::high_resolution_clock::now();
        auto duration_fill_map1 = std::chrono::duration_cast<std::chrono::microseconds>(end_fill_map1 - start_fill_map1).count();

        // Benchmark filling map2
        auto start_fill_map2 = std::chrono::high_resolution_clock::now();
        for (std::size_t i = 0; i < size; ++i) {
            MyString2 key2{std::to_string(i)};
            map2[key2] = static_cast<int>(i);
            keys2.push_back(key2);
        }
        auto end_fill_map2 = std::chrono::high_resolution_clock::now();
        auto duration_fill_map2 = std::chrono::duration_cast<std::chrono::microseconds>(end_fill_map2 - start_fill_map2).count();

        // Output fill times
        std::cout << "Size: " << size << std::endl;
        std::cout << "Time to fill map1 (MyString1): " << duration_fill_map1 << " microseconds" << std::endl;
        std::cout << "Time to fill map2 (MyString2): " << duration_fill_map2 << " microseconds" << std::endl;

        // Benchmark retrieving from map1
        auto start_retrieve_map1 = std::chrono::high_resolution_clock::now();
        volatile int value1;  // volatile to prevent optimization
        for (const auto& key : keys1) {
            value1 = map1[key];
        }
        auto end_retrieve_map1 = std::chrono::high_resolution_clock::now();
        auto duration_retrieve_map1 = std::chrono::duration_cast<std::chrono::microseconds>(end_retrieve_map1 - start_retrieve_map1).count();

        // Benchmark retrieving from map2
        auto start_retrieve_map2 = std::chrono::high_resolution_clock::now();
        volatile int value2;  // volatile to prevent optimization
        for (const auto& key : keys2) {
            value2 = map2[key];
        }
        auto end_retrieve_map2 = std::chrono::high_resolution_clock::now();
        auto duration_retrieve_map2 = std::chrono::duration_cast<std::chrono::microseconds>(end_retrieve_map2 - start_retrieve_map2).count();

        // Output retrieval times
        std::cout << "Time to retrieve from map1 (MyString1): " << duration_retrieve_map1 << " microseconds" << std::endl;
        std::cout << "Time to retrieve from map2 (MyString2): " << duration_retrieve_map2 << " microseconds" << std::endl
                  << std::endl;

        // Clear the maps for the next iteration
        map1.clear();
        map2.clear();
    }

    return 0;
}
