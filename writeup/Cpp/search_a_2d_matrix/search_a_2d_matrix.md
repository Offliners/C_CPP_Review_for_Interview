# Search a 2D Matrix
Detail : [link](https://leetcode.com/problems/search-a-2d-matrix/)

You are given an `m x n` integer matrix `matrix` with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return `true` if `target` is in `matrix` or `false` otherwise.

You must write a solution in `O(log(m * n))` time complexity.

### Solution 1 - Brute Force
* Time complexity: $O(M * N)$
* Space complexity: $O(1)$

### Solution 2 - Optimization Solution One
* Time complexity: $O(M + N)$
* Space complexity: $O(1)$

### Solution 3 - Binary Search
* Time complexity: $O(log(M * N))$
* Space complexity: $O(1)$

## Usage
```shell
$ mkdir build && cd build
$ cmake ..
$ make
$ cd ..
$ python3 compare.py
```

## Result
Test on testcases generated by myself

|       | Runtime (ms) | Memory (Kb) |
|-------|--------------|-------------|
| Sol 1 | 5            | 7           |
| Sol 2 | 3            | 7           |
| Sol 2 | 2            | 7           |
