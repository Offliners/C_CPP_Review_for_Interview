# Best Time to Buy and Sell Stock
Detail : [link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

You are given an array `prices` where `prices[i]` is the price of a given stock on the `i-th` day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return `0`.

### Solution 1 - Brute Force
* Time complexity: $O(n^2)$
* Space complexity: $O(1)$

### Solution 2 - Optimization Solution 1
* Time complexity: $O(n)$
* Space complexity: $O(1)$

### Solution 3 - Two Pointers
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
| Sol 1 | 318          | 7           |
| Sol 2 | 10           | 7           |
| Sol 3 | 9            | 7           |