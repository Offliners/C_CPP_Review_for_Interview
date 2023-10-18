# Chatper 4 - 指標與陣列
### 陣列快速回顧
陣列是連續的同質 (homogeneous)元素的集合，能夠透過索引取得個別元素。連續表示陣列中所有的元素是記憶體中是緊接著不放，彼此之間不存在空隙，同值是指陣列中的元素型別都相同。

※ 陣列長度是固定不便，宣告陣列時就必須決定陣列的大小，指定太大的長度浪費記憶體空間，指定太小則限制能處理的元素個數。realloc函數與動態陣列提供處理需要改變大小的陣列技巧，藉由一些額外的程式碼，就能改變陣列的大小，使用適當的記憶體數量。

### 一維陣列
一維陣列是個線性資料結構，使用一個索引值存取其中的元素，以下是一個包含五個整數的陣列宣告:
```c
int vector[5];
```

![Figure 4-1](./Fig/Figure4-1.png)

陣列的內部表示方式中沒有任何與包含元述數量相關的資訊，陣列名稱只是參照到某個記憶體區塊，對陣列使用sizeof運算子會傳回配置給陣列的位元組數量，必須將陣列大小除以所包含元素的大小才能取得元素各數:
```c
printf("%d\n", sizeof(vector)/sizeof(int));  // 顯示5
```

一維陣列可以利用區塊型別命令初始化:
```c
int vector[5] = {1, 2, 3, 4, 5};
```

### 二維陣列
二維陣列使用列與行存取陣列中的元素:
```c
int matrix[2][3] = {{1,2,3},{4,5,6}};
```

![Figure 4-2](./Fig/Figure4-2.png)

二維陣列被視為陣列的陣列，也就是指用一個索引值存取陣列元素時，會得到指向對應列的指標，以下程式示範取得每一列的位址並顯示對應的大小:
```c
for (int i = 0; i < 2; i++) {
    printf("&matrix[%d]: %p sizeof(matrix[%d]): %d\n", i, &matrix[i], i, sizeof(matrix[i]));
}
```

輸出結果為:
```shell
&matrix[0]: 100 sizeof(matrix[0]): 12  # 由於每列包含3個4位元組的元素
&matrix[1]: 112 sizeof(matrix[1]): 12
```

### 多維陣列
多維陣列有二個或者更多維度，與二維陣列相同，需要更多組括號定義陣列的類型與大小，以下範例定義了喔個三維陣列:
```c
int arr3d[3][2][4] = {
    {{1, 2, 3, 4}, {5, 6, 7, 8}},
    {{9, 10, 11, 12}, {13, 14, 15, 16}},
    {{17, 18, 19, 20}, {21, 22, 23, 24}}
};
```

![Figure 4-3](./Fig/Figure4-3.png)

### 指標表示法與陣列
指標在處理陣列時十分有用，能夠與現有陣列一同使用或是從堆積配置記憶體，再將配置的記憶體視為陣列使用。陣列表示法與指標表示法在一定程度上能夠互換使用，然而兩者並非完全相同。

單純使用陣列名稱會傳回陣列的位址，並指派給指標:
```c
int vector[5] = {1, 2, 3, 4, 5};
int *pv = vector;
```

pv變數指向陣列中第一個元素的指標而非陣列本身，當指派給數值給pv時，指派的是陣列第一個元素的位址。

能夠只用陣列名稱或是透過取址運算子取得陣列第一個元素的位址，以下兩行程式碼有相同的作用，都會傳回vector的位址:
```c
printf("%p\n",vector);
printf("%p\n",&vector[0]);  // 取址運算子的寫法較為複雜但也較明確
```

有時候會使用&vector取得陣列位址，這與其他表示法不同，這種表示法會傳回整個陣列的指標，另外兩種表示法取得的是指向整數的指標。

指標也可以使用索引值，pv[i]表示式予以下指令等價:
```c
*(pv + i)
```

pv指標是記憶體區塊的位址，小括號會取得pv中的位址，再透過指標運算加上索引i的值，所得出的位址經由解參考運算取得其中數值。

指標加上整數會將位址增加整數乘上所指向資料型別的大小，同樣地，如果將陣列名稱加上整數，以下兩者運算有相同效果:
```c
*(pv + i)
*(vector + i)
```

|數值|等效運算|||
|-|-|-|-|
|92|&vector[-2]|vector - 2|&pv[-2]|pv - 2|
|100|vector|vector+0|&pv[0]|pv|
|100|&vector[0]|vector+0|&pv[0]|pv|
|104|&vector[1]|vector + 1|&pv[1]|pv + 1|
|140|&vector[10]|vector + 10|&pv[10]|pv + 10|

![Figure 4-4](./Fig/Figure4-4.png)

陣列表示法可以視為「位移與解參考」運算，vector[2]表示式代表從vector開始，也就是一個指向陣列開頭的指標向右位移兩個位置，然而再解參考位址取得其中的數值。

以下示範了使用指標實作向量乘上常量運算，將輸入的數值與向量中的每個元素相乘:
```c
pv = vector;
int value = 3;
for(int i=0; i<5; i++) {
    *pv++ *= value;
}
```

### 陣列與指標的差異
使用陣列與使用指向陣列指標間有幾個不同的地方:
```c
int vector[5] = {1, 2, 3, 4, 5};
int *pv = vector;
```

vector[i]產生的機器碼與*(vector+i)產生的機器碼不同，vector[i]產生的機器碼會從vector開始，移動i個位置，再使用其內容；*(vector+i)產生的機器碼則會從位置vector開始，將位址加上i，然後使用該位址的內容。雖然結果相同，但產生的機器碼不同。

sizeof運算子對陣列與指向陣列指標會產生不同的結果，對vector執行sizeof運算會得到20，也就是配置給陣列的記憶體數量。對pv使用sizeof運算子則傳回4，指標能夠透過指派新值指向記憶體不同的位置。

```c
pv = pv + 1;
vector = vector + 1;  // 語法錯誤
```

無法修改vector變數，只能修改陣列內容，然而，vector+1運算並不會有任何問題:
```c
pv = vector + 1;
```

### 使用malloc建立一維陣列
如果是從堆積配置記憶體指派給指標，就可以對指標使用陣列索引表示法，將記憶體視為陣列:
```c
int *pv = (int*) malloc(5 * sizeof(int));
for(int i=0; i<5; i++) {
    pv[i] = i+1;
}
```

也可以用如下的指標表示法，然而，陣列表示法看起來表較清楚:
```c
for(int i=0; i<5; i++) {
    *(pv+i) = i+1;
}
```

![Figure 4-5](./Fig/Figure4-5.png)

這個技巧將配置的記憶體區塊視為陣列，大小在執行期間決定，然而，切記不使用資料時要釋放記憶體。

※ 在之前的範例中使用*(pv+i)而非*pv+i，因為解參考比加法優先，第二個式子會先解參考指標，得到指標參照位址的數值，再將這個整數值加上i。此外，如果使用這個表示式作為lvalue，編譯器會發出錯誤訊息。因此，需要先強制執行加法，再作解參考院算，才能夠得到預期的數值。

### 使用realloc函數改變陣列大小
使用realloc函數能夠改變由malloc所建立的陣列大小。為了示範realloc函數，需要時做從標準輸入讀取字元，將讀取的字元指派至緩衝區的函數。緩衝區包含代表輸入結束的return字元外的所有字元，由於無法在事前知道使用者會輸入多少字元，無法決定緩衝區正確的大小，因此使用realloc函數讓緩衝區以固定大小成長。
```c
char* getLine(void) {
    const size_t sizeIncrement = 10;
    char* buffer = malloc(sizeIncrement);
    char* currentPosition = buffer;
    size_t maximumLength = sizeIncrement;
    size_t length = 0;
    int character;
    if(currentPosition == NULL) { return NULL; }
    while(1) {
        character = fgetc(stdin);
        if(character == '\n') { break; }
        if(++length >= maximumLength) {
            char *newBuffer = realloc(buffer, maximumLength += sizeIncrement);
            if(newBuffer == NULL) {
                free(buffer);
            return NULL;
            }
            currentPosition = newBuffer + (currentPosition - buffer);
            buffer = newBuffer;
        }
        *currentPosition++ = character;
    }
    *currentPosition = '\0';
    return buffer;
}
```

在getLine函數中有以下變數:
|變數名稱|功用|
|-|-|
|sizeIncrement|緩衝區初始大小以及每次成長的大小|
|buffer|指向讀取字元的指標|
|currentPosition|指向緩衝區中下個字元存放位置的指標|
|maximumLength|緩衝區終能安全存放的最大字元數|
|length|已讀取的字元數|
|character|目前讀入的字元|

緩衝區一開始建立時的大小是sizeIncrement，如果malloc函數無法配置足夠的記憶體，第一個if命令就會讓函數傳回NULL結束。接著進入第一個無窮迴圈，每次處理一個字元，離開迴圈時會在buffer的結尾加上字元的終止字元NULL，並傳回位址。

在while迴圈中會毒入第一個字元，如果是換行字元，就會離開迴圈，接著，利用if命令判斷是否超過buffer的容許大小，未超過容許大小就會將讀入的字元加在緩衝區最後的位置。

如果達到緩衝區空間的大小，使用realloc函數建立新的記憶體區塊會比園區塊增加sizeIncrement位元組的空間，如果無法配置新區塊則是放原有緩衝區，強制結束函數傳回NULL。否則，調整currentPosition到新緩衝區中適當的位置，並將buffer變數指向新配置的緩衝區。realloc函數不一定會將記憶體配置在原來的位置，因此必須使用函數傳回的指標作為新的、調整過大小的記憶體區塊。