# 常見 C 語言觀念題目總整理

## Table of Content
- [常見 C 語言觀念題目總整理](#---c----------)
  * [Table of Content](#table-of-content)
  * [一、指標](#----)
    + [1. 基礎指標判讀](#1-------)
    + [2. 指標與其他關鍵字混用](#2-----------)
  * [二、call by value, call by reference](#--call-by-value--call-by-reference)
  * [三、變數範圍和生命周期（關鍵字 static）](#----------------static-)
  * [Reference](#reference)

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
關鍵字 volatile 等等判讀方式相同。

## 二、call by value, call by reference
1. call by value : 最常見的函式寫法，呼叫者和被呼叫者的變數各自佔有記憶體，將參數複製再傳給函式。
2. call by reference : 呼叫者和被呼叫者的變數使用相同的記憶體位址，因此在被呼叫函式中改變變數時，變動結果會保留。(C++ 才有，寫法為 type func(type &var) { ... })

C 語言之父明確表示 C 語言只有 call by value。坊間有 call by address 的說法其實是方便教學，指的是對指標變數進行操作的 call by value，具體的執行效果和 call by reference 一樣。

## 三、變數範圍和生命周期（關鍵字 static）
1. local 變數 : local 變數僅活在該函式內，存放位置在 stack 或 heap 記憶體中。
2. static 變數 : static 變數生命周期 (life time) 跟程式一樣長，而範圍 (scope) 則維持不變，即在宣告的函式之外仍無法存取 static 變數。
3. global 變數 : 所有區段皆可使用此變數。

除了範圍不同，static 變數只有宣告的檔案可以使用；而 global 變數可加上 extern 關鍵字修飾，即可在其他檔案以 .h 標頭檔方式使用該變數 (也就是 internal linkage 和 external linkage 的不同)。

* Stack : 存放函數的參數、區域變數等，由空間配置系統自行產生與回收。(會稱作 stack 是由於其配置遵守 LIFO)
* Heap : 一般由程式設計師分配釋放，執行時才會知道配置大小，如 malloc/new 和 free/delete。(注意其資料結構不是 DS 中的 heap 而是 link-list)
* Global : 包含 BSS (未初始化的靜態變數)、data section (全域變數、靜態變數) 和 text/code (常數字元)。

![program_in_memory2](./program_in_memory2.png)

配置練習
```c
int a=0;   //global 初始化區
char *p1;  //global 未初始化區
main(){
    int b;             // stack
    char s[]="abc";    // stack
    char *p2;          // stack
    char *p3="123456"; // 123456\0 在常量區，p3在stack。
    static int c=0;   // global (static) 初始化區
    p1 = (char*)malloc(10);
    p2 = (char*)malloc(20);  //分配得來得10和20位元組的區域在heap
    strcpy(p1,"123456");  
    //123456\0 在常量區，編譯器可能會將它與 p3 中的 123456\0 優化成一個地方。
}
```

static 練習
```c
static int num_a;
// 專屬於整個檔案的全域變數，其他檔案不能存取

void func (int num_b) { // stack 區 
 int num_c; // stack 區

 static int num_d; 
 //scope不變，只能在函數 func 內呼叫，但 lifetime 是整支程式執行的時間。
}
```

## Reference
* Mr. Opengate - 常見 C 語言觀念題目總整理（適合考試和面試）: [Link](https://www.mropengate.com/2017/08/cc-c.html)