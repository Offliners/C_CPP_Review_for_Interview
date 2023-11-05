# Palindrome Linked List
Detail : [link](https://leetcode.com/problems/palindrome-linked-list/)

Given the `head` of a singly linked list, return `true` if it is a palindrome or `false` otherwise.

### Solution 1 - Brute Force
* Time complexity: $O(n)$
* Space complexity: $O(n)$

### Solution 2 - Reverse Linked List
* Time complexity: $O(n)$
* Space complexity: $O(1)$

### Solution 3 - Reverse the End Half of Linked List
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
| Sol 1 | 10           | 7           |
| Sol 2 | 9            | 7           |
| Sol 3 | 8            | 7           |