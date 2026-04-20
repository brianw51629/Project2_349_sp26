# CSC 349: Design and Analysis of Algorithms
## Assignment 2 — Divide and Conquer

This project implements three approaches for finding a missing integer in a sorted sequence.

The three parts are:

- a **linear** approach that scans through the sequence
- a **binary-search-based** divide-and-conquer approach for the case where all elements are distinct
- a **divide-and-conquer** approach for the general case where duplicates may appear

The final combined solution uses the binary-search-based approach when possible and falls back to the general divide-and-conquer approach when necessary.

---

## Files

- `algorithms.h`  
  Header file containing function declarations.

- `algorithms.cc`  
  Implementation of the missing-element algorithms.

- `unittest.cc`  
  Unit tests covering all three parts of the assignment.

---

## Implemented Functions

### `find_missing_linear(const std::vector<int>& A)`
A linear scan that checks consecutive elements and returns the missing value when a gap larger than 1 is found.

### `find_missing_distinct(const std::vector<int>& A)`
A binary-search-based algorithm for sorted sequences with distinct elements.

### `find_missing_general(const std::vector<int>& A)`
A divide-and-conquer algorithm for the general case where duplicates may appear.

### `find_missing_element(const std::vector<int>& A)`
The final combined solution. It first attempts the distinct-element strategy when safe, and otherwise uses the general divide-and-conquer method.

---

## Running the Tests

Compile and run the unit tests with:

```bash
g++ -O3 algorithms.cc unittest.cc -o unit_test && ./unit_test
````

If all tests pass, the program will print:

```text
All tests passed.
```

---

## Test Coverage

The unit tests cover:

* **Part 1:** linear search
* **Part 2:** binary-search-based search on distinct elements
* **Part 3:** divide-and-conquer search when duplicates may appear
* the final combined algorithm

---

## Example Inputs

### Linear / Distinct Case

```text
1, 2, 4, 5, 6, 7, 8
```

Missing element:

```text
3
```

### Distinct Binary-Search Case

```text
-2, -1, 0, 1, 3, 4, 5, 6, 7, 8, 9
```

Missing element:

```text
2
```

### General Divide-and-Conquer Case

```text
-1, -1, 0, 1, 3, 3, 4, 5, 5, 6, 7
```

Missing element:

```text
2
```

```
```
Yes — that is the missing piece. The README needs the **problem-development text**, not just the implementation summary.

What you want is the assignment to read like the original academic progression:

1. start with the missing-elements problem
2. motivate the naïve linear solution
3. specialize to the distinct-elements case
4. motivate the binary-search-based divide-and-conquer solution
5. generalize to duplicates
6. motivate the merge-sort-style divide-and-conquer fallback

Here is a much better `README.md` that restores that structure and keeps your submission/testing preferences.

````md
# CSC 349: Design and Analysis of Algorithms
## Assignment 2 — Divide and Conquer
**Due: January 22nd**

Divide and conquer algorithms solve a problem by dividing it into smaller subproblems, solving those subproblems recursively, and then combining the resulting subsolutions into a solution to the original problem. Depending on the original problem, this could reduce the number of subproblems that must be solved, or it could merely reorganize the order in which they are solved.

In this assignment, you will implement and test algorithms for finding a missing integer in a sorted sequence.

---

## Part 1: Submission Process

1. **Starter Code:** Create a **branch** or a fork of the provided starter code repository.
2. **Implementation:** Complete the logic in `algorithms.cc`.
3. **Testing:** Run the provided unit tests to verify correctness.
4. **Public URL:** Submit the **public URL** of your GitHub repository (specifically the branch containing your work) to [LMS Link].
   - *Note: Ensure your repository is set to Public so the grading scripts can access your code.*

---

## Part 2: Finding Missing Elements

Suppose that you are given a sorted sequence of multiple integers, within which exactly one of the possible integers — that is, one of the integers between the first and last elements — is missing. For example:

```text
1, 2, 4, 5, 6, 7, 8
````

In the above sequence, the missing element is `3`.

Because the sequence is sorted, any successive elements that both appear should differ by exactly 1 unless the missing element lies between them. As a result, the missing element can be found naïvely in linear time by iterating over the sequence and checking whether two consecutive elements differ by more than 1.

This project includes a **linear search** implementation for that baseline approach.

---

## Part 3: A Binary-Search-Based Approach

Now suppose further that all elements in the sequence are distinct. Exactly one element within the possible range does not appear, and no element appears two or more times. For example:

```text
-2, -1, 0, 1, 3, 4, 5, 6, 7, 8, 9
```

In the above sequence, the missing element is `2`.

In this setting, it becomes possible to discard subproblems that cannot possibly contain the missing element, in a manner similar to binary search. Rather than scanning the entire sequence, an efficient divide-and-conquer algorithm can compare the expected value at an index with the actual value stored there, and then recurse only on the half that may still contain the missing value.

This project includes a **binary-search-based** implementation for that distinct-elements case.

---

## Part 4: A Divide-and-Conquer Approach

Now suppose, as a generalization of the above examples, that elements need not be distinct and may appear two or more times. For example:

```text
-1, -1, 0, 1, 3, 3, 4, 5, 5, 6, 7
```

In the above sequence, the missing element remains `2`.

However, once duplicates are allowed, it is no longer generally possible to determine in constant time which subproblem must contain the missing element. The binary-search-style argument breaks down, because repeated values can prevent us from safely discarding half of the sequence.

As a result, all relevant subproblems may need to be explored, in a manner similar to merge sort. Such an approach has linear complexity, since it may still need to inspect the entire sequence in the worst case.

This project includes a **divide-and-conquer** implementation for that more general case.

---

## Part 5: Combined Strategy

You now have three approaches for reasoning about this problem:

1. a **linear** approach
2. a **binary-search-based** approach for the distinct-elements case
3. a **divide-and-conquer** approach for the general case when duplicates may appear

The final combined solution first attempts the binary-search-based strategy when it is safe to do so. If that approach cannot be applied safely because duplicates are present, the algorithm falls back to the general divide-and-conquer method.

This gives a solution that may run in `O(log n)` time when the input is well-structured, while still correctly handling the general case in `O(n)` time.

---

## Part 6: Files

* `algorithms.h`
  Header file containing function declarations.

* `algorithms.cc`
  Implementation of the missing-element algorithms.

* `unittest.cc`
  Unit tests covering all parts of the assignment.

---

## Part 7: Implemented Functions

### `find_missing_linear(const std::vector<int>& A)`

Implements the naïve linear scan.

### `find_missing_distinct(const std::vector<int>& A)`

Implements the binary-search-based algorithm for sorted sequences with distinct elements.

### `find_missing_general(const std::vector<int>& A)`

Implements the divide-and-conquer algorithm for the general case where duplicates may appear.

### `find_missing_element(const std::vector<int>& A)`

Implements the final combined solution:

* first attempt the binary-search-based approach when appropriate
* otherwise fall back to the general divide-and-conquer approach

---

## Part 8: Testing

Before submitting, ensure that your implementation passes the provided unit tests.

### 1. Unit Testing (`unittest.cc`)

**Command:** `g++ -O3 algorithms.cc unittest.cc -o unit_test && ./unit_test`

If all tests pass, the program will print:

```text
All tests passed.
```

### 2. Test Coverage

The unit tests cover:

* **Linear search**
* **Binary-search-based search on distinct elements**
* **Divide-and-conquer search when duplicates may appear**
* **Final combined algorithm**

---

## 💡 C++ Survival Tips

* In the linear approach, compare consecutive elements and look for a gap greater than 1.
* In the distinct-elements case, compare the expected value at an index with the actual value to determine which half may still contain the missing element.
* In the duplicates case, do not assume that one half can always be discarded safely.
* Always compile with the `-O3` flag when running the provided tests.

```

This version restores the academic motivation and progression that was missing.
```
