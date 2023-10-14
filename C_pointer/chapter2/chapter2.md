# Chatper 2 - C語言的動態記憶體管理
### 動態記憶體配置
C語言中動態記憶體配置的基本程序如下:
1. 使用malloc等函數配置記憶體
2. 依應用程式需要使用所配置的記憶體
3. 使用free函數釋放記憶體

```c
int *pi = (int*) malloc(sizeof(int));
*pi = 5;
printf("*pi: %d\n", *pi);
free(pi);
```

![Figure 2-1](./Fig/Figure2-1.png)

malloc函數只有一個指定需要配置記憶體數量的參數，配置成功會回傳在堆積中配置的記憶體位址，失敗則傳回NULL指標。sizeof運算子能提高程式可攜性，正確計算出需要配置的位元組數量。

以下試著配置足夠存放一個整數的記憶體，假設整數大小為4:
```c
int *pi = (int*) malloc(4);
```

由於整數的大小依據使用的記憶體模型而異，教友可攜性的做法是使用sizeof運算子，在任何環境都會傳回正確的大小。

※ 以下是解參考運算子常見的使用錯誤:
```c
int *pi;
*pi = (int*) malloc(sizeof(int));
```
問題出在指派運算子的左側解參考了指標，這會將malloc傳回的位址指派給pi參照的記憶體，如果這是指標的第一次指派，那指標所參照到的記憶體可能不是合法記憶體，正確的用法是:
```c
pi = (int*) malloc(sizeof(int));
```
這種情況並不需要使用解參考運算子。

※ 每個malloc函數 (或其他類似函數)呼叫不再需要配置的記憶體時，就要有對應的free函數呼叫，釋放配置的記憶體以避免記憶體洩漏。

### 記憶體洩漏
記憶體洩漏發生於配置的記憶體已不再使用卻也沒釋放的情況，可能原因為:
1. 遺失記憶體位址
2. 應該呼叫卻沒有呼叫free函數 (這有時稱為隱藏的洩漏)

記憶體洩漏的問題在於無法回收記憶體供後續使用，以下程式碼chunk變數被指派了配置在堆積的記憶體，然而在配置下一塊記憶體前並沒有釋放記憶體，最後應用程式會因為用完記憶體而不正常終止
```c
char *chunk;
while (1) {
    chunk = (char*) malloc(1000000);
    printf("Allocating\n");
}
```

### 遺失記憶體位址
下列程式碼，當pi再次被指派新的位址時會遺失記憶體位址，當第二次pi指派了位址時，就遺失了第一次配置的位址:
```c
int *pi = (int*) malloc(sizeof(int));
*pi = 5;
...
pi = (int*) malloc(sizeof(int));
```

位址500的記憶體沒有被釋放，而程式也不再持有這個位址的參考。

![Figure 2-3](./Fig/Figure2-3.png)

接下來的例子為字串配置了記憶體並初始化，再逐一字元顯示:
```c
char *name = (char*)malloc(strlen("Susan")+1);
strcpy(name,"Susan");
while(*name != 0) {
    printf("%c",*name);
    name++;
}
```

雖然在迴圈中逐次增加了name的值，最後name還是指向字串的NULL終止字元，但遺失了配置給字串使用的起始位址。

![Figure 2-4](./Fig/Figure2-4.png)

### 動態記憶體配置函數
以下介紹函數可以在大多數系統的`stdlib.h`標頭檔中找到:
* malloc
* realloc
* calloc
* free

|函數|說明|
|-|-|
|malloc|從堆積配置記憶體|
|realloc|根據之前配置的記憶體區塊重新配置不同大小的記憶體|
|calloc|從堆積配置記憶體並填入0|
|free|將記憶體區塊歸還至堆積|

動態記憶體是從堆積開始配置，記憶體配置呼叫成功並不保證配置記憶體的順序連續性，但所配置的記憶體會根據指標的資料型別對齊。

### 使用malloc
malloc函數是從堆積配置記憶體區塊，唯一的參數是指定配置的位元組數量，傳回值是void型別指標，如鬼沒有足夠的記憶體則傳回NULL，函數原型如下:
```c
void* malloc(size_t);
```

以下是malloc常見的使用方式:
```c
int *pi = (int*) malloc(sizeof(int));
```

malloc函數執行時會做以下三件事:
1. 從堆積配置一塊記憶體
2. 記憶體內容不會特別修改或清除
3. 傳回第一個位元組的位址

※ 由於malloc函數無法配置記憶體時可能會傳回NULL值，比較好的做法是在使用指標前先檢查是否為NULL值:
```c
int *pi = (int*) malloc(sizeof(int));
if(pi != NULL) {
    // Pointer should be good
} else {
    // Bad pointer
}
```

### 轉型或不轉型
在C語言引進void指標前，需要明確的將malloc傳回值轉型成使用的資料型別，否則會產生不相容資料型別指派的警告訊息。由於void指標能夠指派給其他類型指標，便不再需要明確的轉型，但某些開發人員認為明確的轉型是比較好的做法，原因如下:
1. 能夠記錄,alloc函數的目的
2. 能讓程式碼相容於C++ (以及早期的C編譯器)，這些都需要明確的轉型

### 未配置記憶體
如果宣告指標卻沒有在使用前先配置記憶體，那指標指向的記憶體內容會是垃圾，通常會造成不合法的記憶體參照，例如以下程式碼:
```c
int *pi;
...
printf("%d\n",*pi);
```

![Figure 2-5](./Fig/Figure2-5.png)

### malloc函數的參數大小錯誤
malloc函數配置記憶體大小時透過參數指定，當使用這個函數配置正確數量的位元組數時需要特別小心。例如，需要配置10個double的空間，就需要配置80個位元組:
```c
double *pd = (double*)malloc(NUMBER_OF_DOUBLES * sizeof(double));
```

※ 指定配置的位元組數量時，盡量使用sizeof運算子為佳

### malloc搭配靜態與全域指標
初始化靜態或全域變數時不能使用函數呼叫，以下程式碼宣告了靜態變數，並試著用malloc初始化:
```c
static int *pi = malloc(sizeof(int));  // 會產生編譯錯誤訊息，全域變數也是一樣
```

靜態變數可以將宣告與初始化分離成兩個步驟以避免這種問題，然而全域變數的宣告未於函數與執行程式之外，無法使用類似的作法，因為指派命令必須位於函數之中:
```c
static int *pi;
pi = malloc(sizeof(int));
```

※ 以編譯器的觀點而言，使用初始化運算子`=`與指派運算子`=`並不相同

### 使用calloc函數
calloc函數會同時配置並清除記憶體，原型如下:
```c
void *calloc(size_t numElements, size_t elementSize);
```

※ 清除記憶體表示將記憶體填入2進位的0值

這個函數會配置numElements與elementSize乘積數量的記憶體，傳回指向記憶體第一個位元組的指標: 如果函數無法配置記憶體則傳回NULL指標。如果numElements或elementSize其中一個是0值，會傳回NULL指標，如果calloc無法配置記憶體，也會傳回NULL指標，並將全域變數errno設為EMOMEM (記憶體不足，out of memory)，這是個POSIX錯誤碼，並非支持所有系統。

以下範例pi配置20個位元組，記憶體內容都設為0:
```c
int *pi = calloc(5,sizeof(int));
```

如果不用calloc，也可以使用malloc搭配memset函數達到相同的效果:
```c
int *pi = malloc(5 * sizeof(int));
memset(pi, 0, 5 * sizeof(int));
```

※ memset函數會將整個記憶體區塊填入相同值，第一個參數是指向要填滿的記憶體區塊的指標，第二個參數是填入區塊的數值，最後一個是參數則是需要填滿的位元數。

需要清空記憶體可以使用calloc，但calloc的執行速度比malloc慢。

※ 現在不再需要使用cfree函數。在早期的C語言，這個函數用來釋放由calloc配置的記憶體。