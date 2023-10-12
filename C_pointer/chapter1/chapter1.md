# Chatper 1 - 入門
## 指標與記憶體
### 記憶體類型:
1. 靜態 Static / 全域 Global
2. 自動 Automatic
3. 動態 Dynamic

|變數類型|範圍|生命週期|
|-|-|-|
|全域|整個檔案|應用程式的生命週期|
|靜態|宣告所在的函數|應用程式的生命週期|
|自動 (區域)|宣告所在的函數|函數執行期間|
|動態|視參考到的指標而定|直到釋放記憶體|

※ 指標變數存放的是記憶體位址，並不含任何能夠得知所參照記憶體資料型別所需的資訊

指標的用途:
1. 建立快速有效率的程式碼
2. 提供更方便解決問題的方法
3. 動態記憶體配置
4. 簡化表達式
5. 利用指標傳遞結構資料，避免傳遞大量資料所造成的負擔
6. 保護以參數傳入函數的資料

![Figure 1-1](./Fig/Figure1-1.png)

下述程式皆會印出n

```c
char *names[] = {"Miller","Jones","Anderson"};
printf("%c\n",*(*(names+1)+2));  // 難懂
printf("%c\n",names[1][2]);      // 易懂
```

指標可能引發的問題:
1. 存取陣列或其他資料結構時超出可用範圍
2. 在可用範圍之外參考自動變數
3. 在記憶體釋放後參考配置在堆積上的記憶體
4. 在配置記憶體前解參考指標

### 宣告指標
```c
int num;  // 整數
int *pi;  // 整數指標
```

![Figure 1-2](./Fig/Figure1-2.png)

以下宣告皆相同，空白取決於使用者的喜好

```c
int* pi;
int * pi;
int *pi;
int*pi;
```

※ 雖然指標不需要初始化就能使用，但初始化才能確保有正確行為

```c
const int *pci;
           ---- pci是個變數
          ----- pci是個指標變數
      --------- pci是個指向整數的指標變數
--------------- pci是個指向整數常數的指標變數
<-------------- 由後往前讀宣告 
```

### 位址運算子
位址運算子&會回傳運算元的位址
```c
num = 0;     // num變數的數值設為0
pi = &num;   // pi設定成指向num的位址


int num;
int *pi = &num;  // 也可以在宣告指標時就將pi指派為num的位址


num = 0;
pi = num;   // Error: invalid conversion from 'int' to 'int*'


pi = (int*)num  // 利用轉型將整數指派給整數指標，執行時可能造成程式異常終止，因為程式可能解參考位址0


// 盡早初始化指標是個好習慣
int num;
int *pi;
pi = &num;
```

![Figure 1-3](./Fig/Figure1-3.png)

### 顯示指標值
```c
int num = 0;
int *pi = &num;
printf("Address of num: %d Value: %d\n",&num, num);
printf("Address of pi: %d Value: %d\n",&pi, pi);
```

輸出結果為
```shell
Address of num: 4520836 Value: 0
Address of pi: 4520824 Value: 4520836
```

|格式|意義|
|-|-|
|%x|以16進位數字顯示位數|
|%o|以8進位數字顯示位數|
|%p|以實作指定的方式顯示數值，一般是指16進位|

```c
printf("Address of pi: %d Value: %d\n",&pi, pi);
printf("Address of pi: %x Value: %x\n",&pi, pi);
printf("Address of pi: %o Value: %o\n",&pi, pi);
printf("Address of pi: %p Value: %p\n",&pi, pi);
```

輸出結果為
```shell
Address of pi: 4520824 Value: 4520836
Address of pi: 44fb78 Value: 44fb84
Address of pi: 21175570 Value: 21175604
Address of pi: 0044FB78 Value: 0044FB84
```

%p與%x的差別在於%p會以大寫顯示16進位數值

在不同平台上用相同的方式顯示指標數值並不容易，一個方式是將指標轉型為void的指標，再用%p印出
```c
printf("Value of pi: %p\n", (void*)pi);
```

### 使用間接運算子解參考指標
間接運算子(*)會回傳指標變數只到的記憶體中的數值
```c
int num = 5;
int *pi = &num;
printf("%p\n",*pi);  // 會顯示5
```

解參考後的數值作為lvalue，lvalue能放在指派運算子左側的運算元，因為被指派了新值，所有的lvalue數值都會被改變

```c
*pi = 200;
printf("%d\n",num);  // 會顯示200
```

### 函數指標
指標也可以指向函數
```c
void (*foo)();
```

### NULL的概念
當NULL被指派給指標時表示沒有指向任何東西。NULL的概念表示指標持有一個不會與其他指標相等的特殊數值，沒有指到記憶體中的任何區域。兩個NULL指標總是相等，但兩者可以有各自的指標型別。NULL在許多函式庫中都定義如下:
```c
#define NULL ((void*)0)
```

※ NULL指標與未初始化指標並不相同，未初始化指標可能持有任何數值，有NULL值的指標則不會參照到記憶體的任何位置

有趣的是可以將0值指派給指標，卻無法將其他數值指派給整數

```c
pi = 0;
pi = NULL;
pi = 100;  // 語法錯誤
pi = num;  // 語法錯誤
```

指標可以用在邏輯表達式中唯一的運算元
```c
// 不是NULL
if(pi) {}  // 如果pi被指派為NULL值，就會被解釋為二進位的0值，在C語言中也代表為False
// 是NULL
else {}    
```

```c
int num;
int *pi = 0;  // 0表示NULL指標
pi = &num;
*pi = 0;      // 0表示整數
```

※ 使用NULL可以明確提醒正在處理的變數是指標

### void指標
void指標是個可以指向任何資料型別的通用指標，有以下特性:
1. void指標與char指標有相同的表達方式與記憶體對齊
2. void指標永遠不會和其他指標相等，然而有兩個指派為NULL的void指標則會相等，void指標的實際行為會依系統而有不同

任何指標皆可以指派給void指標，之後還可以轉型回來原來的指標，轉型後的值會等於原來的指標值
```c
int num;
int *pi = &num;
printf("Value of pi: %p\n", pi);
void* pv = pi;
pi = (int*) pv;
printf("Value of pi: %p\n", pi);
```

輸出結果為
```shell
Value of pi: 100
Value of pi: 100
```

※ 使用void指標時要注意，將指標轉型為void指標後，void指標能夠轉型為任何指標型別，沒有任何限制。

sizeof運算子能夠用在void指標，卻不能用在void之上
```c
size_t size = sizeof(void*);  // 合法
size_t size = sizeof(void);   // 不合法
```

### 全域與靜態指標
```c
int *globalpi;
void foo() {
    static int *staticpi;
    ...
}

int main() {
    ...
}
```

![Figure 1-6](./Fig/Figure1-6.png)

### 指標大小與陣列
處理指標時常需要使用四種內建指標型別
1. `size_t` : 表示空間大小使用的安全型別
2. `ptrdiff_t` : 指標運算使用
3. `intptr_t`與`uintptr_t` : 用來存放指標位址

### 認識size_t
size_t型別表示C語言中所有物件的最大尺寸，也是sizeof回傳的型別

※ 宣告字元數量與陣列索引變數時，使用size_t是好習慣，在迴圈計數、陣列索引以及某些指標運算時都應該使用這個型別

在`stdio.h`與`stdlib.h`中的定義
```c
#ifndef __SIZE_T
#define __SIZE_T
typedef unsigned int size_t;  // 通常size_t的最大值定義為SIZE_MAX
#endif
```

列印size_t時要注意，這個是無號數。建議用`%zu`，在不支援此格式時，可以用`%u`或`%lu`

```c
size_t sizet = -5;
printf("%d\n",sizet);   // 印出 5
printf("%zu\n",sizet);  // 印出 4294967291

// 由於-5是有號數，最高位原為1表示負值，
// 當以無號數來解讀時，最高位元會視為2的次方，因此使用%zu會看到很大的數值

sizet = 5;
printf("%d\n",sizet);   // 印出 5
printf("%zu\n",sizet);  // 印出 5
```

※ size_t是無號數，切記使用正數

### 使用sizeof與指標
sizeof運算子可以取得指標的大小
```c
printf("Size of *char: %d\n",sizeof(char*));
```

輸出結果為
```shell
Size of *char: 4
```

### 使用intptr_t與uintptr_t
intptr_t與uintptr_t型別用於儲存指標位址，會與系統使用的底層指標有相同的大小，uintptr_t為intptr_t的無號版本，uintptr_t的彈性不如intptr_t

```c
int num;
intptr_t *pi = &num;
uintptr_t *pu = &num;  // error: invalid conversion from 'int*' to
                       // 'uintptr_t* {aka unsigned int*}' [-fpermissive]

// uintptr_t與其他型別一同使用時都需要強制轉型 
char c;
uintptr_t *pc = (uintptr_t*)&c;
```

※ 避免將指標轉型成整數，在64位元指標的情況下，如果整數大小是4位元將會遺失大部分資訊