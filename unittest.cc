#include "algorithms.h"

#include <cassert>
#include <iostream>
#include <vector>

void test_linear_case(const std::vector<int>& A, int expected) {
    assert(find_missing_linear(A) == expected);
}

void test_distinct_case(const std::vector<int>& A, int expected) {
    assert(find_missing_distinct(A) == expected);
}

void test_general_case(const std::vector<int>& A, int expected) {
    assert(find_missing_general(A) == expected);
}

void test_combined_case(const std::vector<int>& A, int expected) {
    assert(find_missing_element(A) == expected);
}

int main() {
    // Naive linear search
    test_linear_case({1, 2, 4, 5, 6, 7, 8}, 3);
    test_linear_case({-2, -1, 0, 1, 3, 4, 5, 6, 7, 8, 9}, 2);
    test_linear_case({-1, -1, 0, 1, 3, 3, 4, 5, 5, 6, 7}, 2);
    test_linear_case({0, 0, 1, 1, 2, 4, 4}, 3);

    // Part 2: distinct-elements binary-search-based approach
    test_distinct_case({1, 2, 4, 5, 6, 7, 8}, 3);
    test_distinct_case({-2, -1, 0, 1, 3, 4, 5, 6, 7, 8, 9}, 2);
    test_distinct_case({5, 6, 7, 8, 10}, 9);
    test_distinct_case({10, 11, 12, 14, 15, 16}, 13);

    // Part 3: duplicates-allowed general approach
    test_general_case({-1, -1, 0, 1, 3, 3, 4, 5, 5, 6, 7}, 2);
    test_general_case({0, 0, 1, 1, 2, 4, 4}, 3);
    test_general_case({10, 10, 11, 12, 12, 14, 14}, 13);
    test_general_case({-5, -4, -4, -3, -1, -1}, -2);

    // Final combined algorithm
    test_combined_case({1, 2, 4, 5, 6, 7, 8}, 3);
    test_combined_case({-2, -1, 0, 1, 3, 4, 5, 6, 7, 8, 9}, 2);
    test_combined_case({-1, -1, 0, 1, 3, 3, 4, 5, 5, 6, 7}, 2);
    test_combined_case({0, 0, 1, 1, 2, 4, 4}, 3);

    std::cout << "All tests passed." << std::endl;
    return 0;
}