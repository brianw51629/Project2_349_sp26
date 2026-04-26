#include "algorithms.h"
#include <climits>

// -----------------------------------------------------------------------------
// Helper: determine whether a portion of the sequence contains duplicates
//
// Pseudocode idea:
// 1. Look through the selected portion of the sequence from left to right.
// 2. Compare each value with the one immediately before it.
// 3. If two neighboring values are the same, then this portion is not distinct.
// 4. Otherwise, this portion is distinct.
// -----------------------------------------------------------------------------
bool all_distinct(const std::vector<int>& A, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        if (A[i] == A[i - 1]) return false;
    }
    return true;
}

// -----------------------------------------------------------------------------
// Part 1: Linear search
//
// Pseudocode idea:
// 1. Start at the beginning of the sequence.
// 2. Compare each value with the next value in the sequence.
// 3. When the difference is larger than expected, the missing value lies there.
// 4. Return that missing value.
// -----------------------------------------------------------------------------
int find_missing_linear(const std::vector<int>& A) {
    for (int i = 0; i + 1 < static_cast<int>(A.size()); i++) {
        if (A[i + 1] - A[i] > 1) {
            return A[i] + 1;
        }
    }
    return INT_MIN;
}

// -----------------------------------------------------------------------------
// Part 2 helper: binary-search-based search on a distinct subarray
//
// Pseudocode idea:
// 1. Work with the current left and right boundaries.
// 2. Repeatedly look at the middle position.
// 3. Decide whether the left side still matches the expected consecutive pattern.
// 4. If it does, continue searching in the right half.
// 5. Otherwise, continue searching in the left half.
// 6. When only one position remains, determine the missing value from that spot.
// -----------------------------------------------------------------------------
int binary_missing_distinct(const std::vector<int>& A, int left, int right) {
    int expected = A[left] - left;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (A[mid] == expected + mid) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return A[left] - 1;
}

// -----------------------------------------------------------------------------
// Part 3 helper: divide-and-conquer search for the general case
//
// Pseudocode idea:
// 1. First handle the smallest subproblems directly.
// 2. If the current portion happens to have all distinct values, use the faster
//    binary-search-based method.
// 3. Otherwise, split the current portion into two smaller parts.
// 4. Recursively search the left part.
// 5. If the answer was not found there, check the gap between the two parts.
// 6. If needed, recursively search the right part.
// -----------------------------------------------------------------------------
int general_missing_recursive(const std::vector<int>& A, int left, int right) {
        if (left >= right) {
            return INT_MIN;
        }

        if (all_distinct(A, left, right)) {
            if (A[right] - A[left] > right - left) {
                return binary_missing_distinct(A, left, right);
            }
            return INT_MIN;
        }

        int mid = left + (right - left) / 2;

        int result = general_missing_recursive(A, left, mid);
        if (result != INT_MIN) {
            return result;
        }

        if (A[mid + 1] - A[mid] > 1) {
            return A[mid] + 1;
        }

        return general_missing_recursive(A, mid + 1, right);
    }

// -----------------------------------------------------------------------------
// Public wrapper for Part 2
//
// Pseudocode idea:
// 1. Run the distinct-elements algorithm on the entire sequence.
// -----------------------------------------------------------------------------
int find_missing_distinct(const std::vector<int>& A) {
        return binary_missing_distinct(A, 0, static_cast<int>(A.size()) - 1);
}

// -----------------------------------------------------------------------------
// Public wrapper for Part 3
//
// Pseudocode idea:
// 1. Run the general divide-and-conquer algorithm on the entire sequence.
// -----------------------------------------------------------------------------
int find_missing_general(const std::vector<int>& A) {
    return general_missing_recursive(A, 0, static_cast<int>(A.size()) - 1);
}

// -----------------------------------------------------------------------------
// Final combined algorithm
//
// Pseudocode idea:
// 1. Check whether the full sequence is distinct.
// 2. If it is, use the binary-search-based algorithm.
// 3. Otherwise, use the general divide-and-conquer algorithm.
// -----------------------------------------------------------------------------
int find_missing_element(const std::vector<int>& A) {
    if (all_distinct(A, 0, static_cast<int>(A.size()) - 1)) {
        return find_missing_distinct(A);
    }
    return find_missing_general(A);
}