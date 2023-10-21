# Chatper 5 - 指標與字串
### 字串的基礎
字串是以ASCII NUL字元結束的字元序列，ASCII的NU字元以\0表示，字串通常儲存在陣列或是配置在堆積的記憶體，並非所有字元都是字串，字元陣列可能不包含NUL字元。char型別的陣列可能用於表示較小的整數型別，如布林值，以節省應用程式的記憶體空間。

C語言中有兩種字串型別:
* 位元組字串 (Byte string)
    - 由char資料型別組成的序列
* 寬字元字串 (Wide string)
    - 由wchar_t資料型別組成的序列

wchar_t資料型別用於寬字元，可能是16或是32字元。這兩種字串都以NUL字元結尾，位元組字串函數一般宣告在string.h檔案中，寬字元字串函數宣告於wchar.h檔案。

※ 切記NULL與NUL並不相同，NULL是特殊指標，一般定義為((void*)0)，NUL則是個定義為'\0'的字元，兩者不該交互使用。

字元常量是以單引號刮起來的字元序列，一般來說只包含一個字元，但也可以包含多個字元，例如跳脫字元:
```c
printf("%d\n",sizeof(char));  // 顯示1
printf("%d\n",sizeof('a'));   // 顯示4
```

### 字串宣告
字串宣告有三種不同的方式: 常量、字元陣列以及字元指標。字串常量是以雙引號刮起來的字元序列，通常用於初始化字串變數。

以下是一個字元陣列，程式宣告了最多能夠存放31個字元的header陣列，由於字串須以NUL結尾，宣告為32個字元大小的陣列實際上只能存放31個字元的字串:
```c
char header[32];
```

以下是個字元指標，還沒有初始化也尚未參照到任何字串，這個時候還沒有指定字串的長度與位置:
```c
char *header;
```

### 字串常量池
定義字串常量時，字串常量常常會被指派到字串常量池 (literal pool)中，這個記憶體區域存放字串組成的字元序列。多次使用相同的常量，一般只會有一份實際的副本存放在字串常量池 (string literal pool)中，這能夠減少應用程式需要的空間。

※ GCC使用 -fwritable-strings選項關閉string pooling。

![Figure 5-1](./Fig/Figure5-1.png)

字串常量經常被配置在唯讀記憶體 (read-only memory)中，使得常量不論使用於全域、靜態或是區域都是不可變。從這個角度而言，字串常量並沒有範圍。

### 當字串常量不是常數
大多數編譯器都將字串常量視為常數，無法修改字串常量的內容，然而，某些編譯器，例如GCC，夠修改字串常量的內容，例如以下範例:
```c
char *tabHeader = "Sound";
*tabHeader = 'L';
printf("%s\n",tabHeader);  // 顯示Lound
```

程式會將常量修改為Lound，一般來說，這並不是預期行為，應該盡量避免，用以下的方式將變數宣告為常數能夠部份解決這個問題:
```c
const char *tabHeader = "Sound";
```

### 字串初始化
字串陣列能夠以初始化運算子初始化，以下範例中，header陣列以字串常量中的字元初始化:
```c
char header[] = "Media Player";
```

由於"Media Player"字串常量有12個字元長，總共需要13個位元組來表示整個常量。陣列會配置13個位元組已持有字串內容，初始化會初始內容字元以及結尾的NUL字元到陣列中。

![Figure 5-2](./Fig/Figure5-2.png)

陣列可以使用strcpy函數初始化，以下程式將字串常量複製到陣列:
```c
char header[13];
strcpy(header,"Media Player");
```

較繁瑣的方式是如以下程式逐一指派個別字元:
```c
header[0] = 'M';
header[1] = 'e';
    ...
header[12] = '\0';
```

※ 以下的指派命令不合法，無法將字串常量指派給陣列名稱:
```c
char header2[];
header2 = "Media Player";
```

### 初始化字元指標
使用動態記憶體配置有較大的彈性，也可以讓記憶體存活較長的時間:
```c
char *header;
```

一般用來初始化字串的方式利用了malloc與strcpy函數配置記憶體並將常量複製到字串:
```c
char *header = (char*) malloc(strlen("Media Player")+1);
strcpy(header,"Media Player");
```

![Figure 5-3](./Fig/Figure5-3.png)

上述範例使用malloc函數時，透過strlen函數與字串常量計算出字串的長度，也可以像以下的程式直接指定字串長度:
```c
char *header = (char*) malloc(13);
```

※ 在計算malloc函數使用的字串長度時:
* 總是加上一個供NUL終止字元使用
* 不要使用sizeof運算子，應該使用strlen函數取得原有字串的長度，sizeof運算子會傳回陣列或指標的大小，而非字串長度

如果不使用字串常量與strcpy函數初始化字串，也可以使用以下方式:
```c
*(header + 0) = 'M';
*(header + 1) = 'e';
    ...
*(header + 12) = '\0';
```

可以直接將字串常量的位址指派給字元指標，如以下程式，這並不會建立新的字串:
```c
char *header = "Media Player";
```

![Figure 5-4](./Fig/Figure5-4.png)

※ 不能以字元常量初始化字元指標，字元常量的型別為int，編譯器會解讀成將整數指派給字元指標，這種作法會在解參考指標時造成應用程式終止:
```c
char* prefix = '+';  // 不合法
```

以下是使用malloc函數的正確做法:
```c
prefix = (char*)malloc(2);
*prefix = '+';
*(prefix+1) = 0;
```

### 透過標準輸入初始化字串
字串也可以透過外部資料來初始化，例如標準輸入，從標準輸入讀取字串可能發生初始化錯誤，例如以下程式碼:
```c
char *command;
printf("Enter a Command: ");
scanf("%s", command);  // command變數使用前沒有指派可用記憶體
```

要解決此問題，應該先為指標配置記憶體或使用固定大小的陣列而非指標。

