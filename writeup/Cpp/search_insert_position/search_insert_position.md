# Search Insert Position
Detail : [link](https://leetcode.com/problems/search-insert-position/)

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with `O(log n)` runtime complexity.

### Solution 1 - Brute Force
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
| Sol 1 | 6            | 7           |
| Sol 2 | 4            | 7           |
