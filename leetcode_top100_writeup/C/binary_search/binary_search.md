# Binary Search
Detail : [link](https://leetcode.com/problems/binary-search/)

Given an array of integers `nums` which is sorted in ascending order, and an integer `target`, write a function to search `target` in `nums`. If `target` exists, then return its index. Otherwise, return `-1`.

You must write an algorithm with `O(log n)` runtime complexity.

### Solution 1 - Linear Search
* Time complexity: $O(n)$
* Space complexity: $O(1)$

### Solution 2 - Binary Search
* Time complexity: $O(log n)$
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
| Sol 1 | 4            | 7           |
| Sol 2 | 2            | 7           |