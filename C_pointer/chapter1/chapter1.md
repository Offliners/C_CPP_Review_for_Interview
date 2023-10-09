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