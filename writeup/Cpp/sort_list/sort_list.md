# Sort List
Detail : [link](https://leetcode.com/problems/sqrtx)

Given the `head` of a linked list, return the list after sorting it in ascending order.

![sort_list_1](./sort_list_1.jpg)

### Solution 1 - Brute Force
* Time complexity: $O(nlog n)$
* Space complexity: $O(n)$

### Solution 2 - Bubble Sort
* Time complexity: $O(n^2)$
* Space complexity: $O(1)$

### Solution 3 - Merge Sort
* Time complexity: $O(nlog n)$
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
| Sol 1 | 10           | 8           |
| Sol 2 | 3536         | 8           |
| Sol 3 | 11           | 8          |