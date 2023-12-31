# Maximum Subarray
Detail : [link](https://leetcode.com/problems/maximum-subarray/)

Given an integer array `nums`, find the subarray with the largest sum, and return its sum.

### Solution 1 - Brute Force
* Time complexity: $O(n^2)$
* Space complexity: $O(1)$

### Solution 2 - Divide and Conquer
* Time complexity: $O(nlog n)$
* Space complexity: $O(log n)$

### Solution 3 - Dynamic Programming
* Time complexity: $O(n)$
* Space complexity: $O(n)$

### Solution 4 - Kadane's Algorithm
* Time complexity: $O(n)$
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
| Sol 1 | 769          | 7           |
| Sol 2 | 11           | 7           |
| Sol 3 | 10           | 7           |
| Sol 4 | 10           | 7           |
