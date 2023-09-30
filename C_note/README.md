# 常見 C 語言觀念題目總整理

## TOC

## 一、指標
指標 (pointer)：一個指向某個儲存位址的變數，語法為

```c
int *ptr = &var;
```

其中
* & : 取變數位址
* \* : 表示為指標變數

也可用於函數變為函式指標 (function pointer)，語法為

```c
void (*fptr)(type_a, type_b) = &func;
```

常用的地方如下
* 函式 sort 時傳入判斷準則
* multithread 傳函數進入建立 thread 的 API 中
* callback function (一種事件導向的函式)

### 1. 基礎指標判讀
指標判讀大原則為「從右讀到左」，例如：
```c
int a; // 一個整數型
int *a; // 一個指向整數的指標
int **a; // 一個指向指標的指標，它指向的指標是指向一個整數型
int a[10]; // 一個有10個整數型的陣列
int *a[10]; // 一個有10個指標的陣列，該指標是指向一個整數型的
int (*a)[10]; // 一個指向有10個整數型陣列的指標
int (*a)(int); // 一個指向函數的指標，該函數有一個整數型參數並返回一個整數
int (*a[10])(int); // 一個有10個指標的陣列，該指標指向一個函數，該函數有一個整數型參數並返回一個整數
```

注意宣告兩個指標時不能寫做 int* a, b; 因為前式等價於 int* a; int b;。連續宣告兩個指標用 int *a, *b;

### 2. 指標與其他關鍵字混用

一樣右讀到左，例如：
```c
const int * foo; // 一個 pointer，指向 const int 變數。
int const * foo; // 一個 pointer，指向 const int 變數。
int * const foo; // 一個 const pointer，指向 int 變數。
int const * const foo; // 一個 const pointer，指向 const int 變數。
```

## Reference
* Mr. Opengate - 常見 C 語言觀念題目總整理（適合考試和面試）: [Link](https://www.mropengate.com/2017/08/cc-c.html)