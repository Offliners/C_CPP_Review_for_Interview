# Contains Duplicate
Given an integer array nums, return `true` if any value appears at least twice in the array, and return `false` if every element is distinct.

### Solution 1 - Brute Force
* Time complexity: $O(n^2)$
* Space complexity: $O(1)$

### Solution 2 - Sorting
* Time complexity: $O(nlogn)$
* Space complexity: $O(1)$

### Solution 3 - Hash Table
* Time complexity: $O(n)$
* Space complexity: $O(n)$

### Solution 4 - Unique
* Time complexity: $O(nlogn)$
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
|       | Runtime (ms) | Memory (Kb) |
|-------|--------------|-------------|
| Sol 1 | 271          | 7           |
| Sol 2 | 24           | 7           |
| Sol 3 | 29           | 7           |
| Sol 4 | 25           | 7           |