/*
 * @author idlab
 * @date 16/08/2022
 */

#include <03_time_complexity/insertion_sort.hpp>
#include <03_time_complexity/quick_sort.hpp>
#include <chrono>
#include <iostream>
#include <vector>
#include <algorithm>
// Declare a type alias for a sorting function
// Let's dissect the function pointer notation:
// The first `std::vector<int>` is the return type of the function
// After that, we have the function name, and an asterisk to mark it as a pointer between ().
// Since the function pointer here is just a type, and not an argument, we can omit the name, which gives us (*).
// If we were to use a function pointer as an argument to a function, we would want to name the argument,
// and we'd get something like (*function_pointer).
// Finally, between the final set of (), we get the argument list for the function, in this case,
// our function accepts 1 argument of type `const std::vector<int>&`, and again, names can be omitted here.
using sort_fn_t = std::vector<int> (*)(const std::vector<int>&);

long timed_sorting_function(
    sort_fn_t sort_fn,                  // Pass a function pointer to the sorting function
    const std::vector<int>& input_data  // The input data
) {
    // TODO: Start Time Measurement
    auto start = std::chrono::high_resolution_clock::now();
    const std::vector<int> sorted = sort_fn(input_data);  // call the function that the function pointer points to,
                                                          // to do the actual sorting.
    auto end = std::chrono::high_resolution_clock::now();

    // TODO: End Time Measurement
    return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();  // TODO: Return Total Time in nanoseconds
}

std::vector<int> generate_input_data(std::size_t size) {
    // TODO: Generate the correct input data!
    std::vector<int> data(size);
    std::generate(data.begin(), data.end(), std::rand);

    return std::vector<int>(data);
}

int main() {
    // We declare a list of function pointers, we can then iterate over this list and use each function
    const std::vector<sort_fn_t> sorting_functions = {insertion_sort, quick_sort};

    // Iterate over a number of different array sizes
    for (std::size_t array_size = 4; array_size < 1000000; array_size *= 2) {
        // Generate a set of input data for each array size
        // NOTE! Its important to give both sorting algorithms the same data, so the comparison is fair
        const std::vector<int> input_data = generate_input_data(array_size);

        // Iterate over all sorting functions, and time each one.
        for (sort_fn_t sort_fn : sorting_functions) {
            // TODO: Print/Save the actual times
            const long sorting_time = timed_sorting_function(sort_fn, input_data);
            std::cout << "Function: " << (sort_fn == &insertion_sort<int> ? "insertion_sort" : "quick_sort")
                      << ", Array size: " << array_size
                      << ", Time (ns): " << sorting_time << std::endl;
        }
    }
}