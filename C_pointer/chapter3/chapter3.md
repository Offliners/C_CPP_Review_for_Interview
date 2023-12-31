# Chatper 3 - 指標與函數
### 程式堆疊
程式堆疊是支援函數執行的記憶體區塊，通常與堆積共用，有就是兩者共享相同的記憶體區域。一般而言程式堆疊占用下半區域，堆積則使用上半部區域。

```c
void function2() {
    Object *var1 = ...;
    int var2;
    printf("Program Stack Example\n");
}
void function1() {
    Object *var3 = ...;
    function2();
}
int main() {
    int var4;
    function1();
}
```

![FIgure 3-1](./Fig/Figure3-1.png)

函數被呼叫時，會建立對應的堆疊框架讓堆疊「向上」成長，函數結束時，堆疊框架會從程式堆疊移除，堆疊框架使用的記憶體不會被清除，而是稍後其他堆疊框架推入程式堆疊時被覆蓋。而動態配置記憶體時會配置在堆積中，讓堆積「向下」成長。

### 堆疊框架的結構
堆疊框架是由幾個部分組成，包含:
* 回傳位址
    - 當函數結束時程是應該恢復的執行位址
* 區域資料儲存空間
    - 配置給區域資料的記憶體
* 參數儲存空間
    - 配置給區域參數的記憶體
* 堆疊與基底指標
    - 執行期系統用於維護堆疊的指標

```c
float average(int *arr, int size) {
    int sum;
    printf("arr: %p\n",&arr);
    printf("size: %p\n",&size);
    printf("sum: %p\n",&sum);
    for(int i=0; i<size; i++) {
        sum += arr[i];
    }
    return (sum * 1.0f) / size;
}
```

輸出結果:
```shell
arr: 0x500
size: 0x504
sum: 0x480
```

建立堆疊框架後，參數會以宣告的相反順序推入堆疊框架，接著是區域變數，全部都依照宣告的相反順序推入。當堆疊框架被推入程式堆疊時，系統可能因為用完所有的記憶體，這個狀況稱為堆疊溢位 (stack overflow)。

![Figure 3-2](./Fig/Figure3-2.png)

### 用指標傳遞資料
用指標傳遞資料的主要目的就是讓函數有修改資料的能力，以下程式實作交換函數
```c
void swapWithPointers(int* pnum1, int* pnum2) {
    // pnum1與pnum2指標在交換過程中進行解參考，這會改變n1與n2的數值
    int tmp;
    tmp = *pnum1;
    *pnum1 = *pnum2;
    *pnum2 = tmp;
}

int main() {
    int n1 = 5;
    int n2 = 10;
    swapWithPointers(&n1, &n2);
    return 0;
}
```

![Figure 3-3](./Fig/Figure3-3.png)

### 用數值傳遞資料
如果沒有將數值以指標的方式傳遞，那就不會發生交換的動作:
```c
// 兩個整數是以數值的方式傳入函數而非以指標傳入，num1與num2兩個參數的數值只是副本
void swap(int num1, int num2) {
    int tmp;
    tmp = num1;
    num1 = num2;
    num2 = tmp;
}

int main() {
    int n1 = 5;
    int n2 = 10;
    swap(n1, n2);
    return 0;
}
```

![FIgure 3-4](./Fig/Figure3-4.png)

### 傳入常數指標
傳入常數指標是C語言中常用的技巧，有很高的效率，因為實際傳遞的只是資料的指標，可以避免複製記憶體中大量的資料，但一般的指標能夠修改資料，如果不希望資料被修改，那傳入的指標就該指向常數資料。

```c
void passingAddressOfConstants(const int* num1, int* num2) {
    // 在函數內部，無法修改以整數常數指標方式傳入的資料
    *num2 = *num1;
}

int main() {
    const int limit = 100;
    int result = 5;
    passingAddressOfConstants(&limit, &result);
    return 0;
}
```

若將100指派給result:
```c
void passingAddressOfConstants(const int* num1, int* num2) {
    *num1 = 100;  // 語法錯誤，修改被作為常數參考到的第一參數
    *num2 = 200;
}

int main() {
    const int limit = 100;
    int result = 5;
    passingAddressOfConstants(&limit, &limit);  // 語法錯誤，第二個參數型別與實際傳入的型別不符合
    return 0;
}
```

以下傳入整數數字的位址也會產生語法錯誤:
```c
// 錯誤訊息說明需要以lvalue做為取址運算子的運算元
passingAddressOfConstants(&23, &23);
```

### 傳回指標
傳回指標很容易，只要將傳回值宣告作為指向適當資料型別的指標就行了，以下是兩個常用的技巧:
* 在函數中使用malloc配置記憶體，再傳回位址。呼叫函數的程式負責釋放傳回的指標。
* 將物件傳入函數供內部修改，呼叫函數的程式負責配置與釋放物件所需的記憶體。

首先示範使用malloc函數配置傳回的記憶體:
```c
int* allocateArray(int size, int value) {
    int* arr = (int*)malloc(size * sizeof(int));
    for(int i=0; i<size; i++) {
        arr[i] = value;
    }
    return arr;
}
```

函數使用如下:
```c
int* vector = allocateArray(5,45);
for(int i=0; i<5; i++) {
    printf("%d\n", vector[i]);
}
```

![Figure 3-5](./Fig/Figure3-5.png)

「之前」圖顯示return命令之前的情況，「之後」圖呈現函數回傳後程式的狀態，vector變數現在持有函數中配置的記憶體位址，雖然arr陣列已經在函數結束後清除，但指標參考到的位址並沒有清除，這塊記憶體作中需要被釋放。

雖然上述範例能夠正確執行，但從函數傳回指標時可能發生許多問題:
1. 傳回未初始化的指標
2. 傳回指向不合法位址的指標
3. 傳回指向區域變數的指標
4. 傳回的指標沒有被適當的釋放

allocateArray函數很可能發生最後一個問題。從函數中傳回動態配置記憶體表示呼叫函數的城市需要負責釋放記憶體:
```c
int* vector = allocateArray(5,45);
...
free(vector);
```

不需要傳回資料時必須釋放記憶體，沒有釋放記憶體會造成記憶體洩漏。

### 區域資料的指標
傳回指向區域變數的指標是不了解程式堆疊運作方式的程式設計師常犯的錯誤，例如以下範例:
```c
int* allocateArray(int size, int value) {
    int arr[size];
    for(int i=0; i<size; i++) {
        arr[i] = value;
    }
    return arr;  // 傳回區域變數未址而非動態配置記憶體
}
```

不幸的是，傳回的陣列在函數結束時就不再合法，函數堆疊框架已經從堆疊中移除，但只要呼叫了其他函數就會覆蓋這些數值:
```c
int* vector = allocateArray(5,45);
for(int i=0; i<5; i++) {
    printf("%d\n", vector[i]);
}
```

![Figure 3-6](./Fig/Figure3-6.png)

另一個方式是將arr變數宣告為靜態變數，雖變數的可視範圍侷限在函數當中，但資料內容配置在堆疊框架之外，避免了其他函數覆蓋變數內容的問題:
```c
int* allocateArray(int size, int value) {
    static int arr[5];
    ...
}
```

每次呼叫allocateArray函數都會重複使用相同的陣列，清除前次呼叫建立的陣列內容。除此之外，靜態陣列必須宣告為固定大小，會限制了函數處理不同陣列大小的能力。

### 傳入NULL指標
當函數接受指標作為參數值，在使用前先檢查是否為NULL指標是個好習慣
```c
int* allocateArray(int *arr, int size, int value) {
    if(arr != NULL) {
        for(int i=0; i<size; i++) {
            arr[i] = value;
        }
    }
    return arr;
}
```

如果指標NULL，不會進行任何動作，程式可以繼續執行不會發生不正常終止。

### 傳入指標的指標
當指標做完參數傳入函數時，是以傳值的方式傳入，如果想要修改原來的指標內容而非指標複本，就必須傳入指標的指標。

在下述的範例中，傳入指向整數陣列的指標，在函數內部初始化，函數透過第一個參數傳回配置的記憶體。函數先配置記憶體再初始化，配置的記憶體位址會指派給指向整數的指標。為了修改由外部傳入的指標，必須傳入指標的位址，因此第一個參數宣告為指向整數指標的指標，呼叫函數時則須傳入指標的位址。
```c
void allocateArray(int **arr, int size, int value) {
    *arr = (int*)malloc(size * sizeof(int));
    if(*arr != NULL) {
        for(int i=0; i<size; i++) {
            *(*arr+i) = value;
        }
    }
}
```

測試函數如下:
```c
int *vector = NULL;
allocateArray(&vector,5,45);
```

allocateArray的第一個參數是以指向整數指標的指標方式傳入，當呼叫函數時，需要傳入相同型別，範例中傳入vector的位址。由malloc傳回的位址指派給arr變數，解參考指向指數指標的指標會得到整數指標，也就是vector的位址，因此會修改vector的數值。

※ 劃出記憶體配置圖是找出記憶體洩漏問題最簡單的方法

![Figure 3-7](./Fig/Figure3-7.png)

以下程式說明為何傳入指標無法產生預期的結果:
```c
void allocateArray(int *arr, int size, int value) {
    arr = (int*)malloc(size * sizeof(int));
    if(arr != NULL) {
        for(int i=0; i<size; i++) {
            arr[i] = value;
        }
    }
}
```

使用方式如下:
```c
int *vector = NULL;
allocateArray(&vector,5,45);
printf("%p\n",vector);
```

執行程式後會輸出0x0，vector傳入函數時是將數值複製為arr參數，修改arr並不會影響vector的數值。函數傳回時儲存在arr的數值並不會複製到vector。除此之外，由於沒有任何指標指向位址600的記憶體，還造成了記憶體洩漏。

![Figure 3-8](./Fig/Figure3-8.png)

### 客製free函數
free函數不會檢查傳入的指標是否為NULL，也不會在釋放後將指標設為NULL，然而釋放指標後將指標設為NULL是個好習慣。

```c
void saferFree(void **pp) {
    if (pp != NULL && *pp != NULL) {
        free(*pp);
        *pp = NULL;
    }
}
```

safeFree函數呼叫free函數釋放記憶體，參數宣告為void指標，使用指標的指標讓程式修改傳入的指標值，void型別則能夠接受所有的指標型別。如果呼叫函數時沒有明確地將指標轉型為void指標便會得到警告，要明確地使用轉型才能避免警告訊息。

以下是safeFree的巨集，在呼叫safeFree前將指標轉型為正確的型別，並使用取址運算子取得位址，讓函數使用者不用額外的轉型與取得指標的位址。
```c
#define safeFree(p) saferFree((void**)&(p))
```

以下為巨集的使用方式:
```c
int main() {
    int *pi;
    pi = (int*) malloc(sizeof(int));
    *pi = 5;
    printf("Before: %p\n",pi);
    safeFree(pi);
    printf("After: %p\n",pi);
    safeFree(pi);
    return (EXIT_SUCCESS);
}
```

假設malloc傳回的記憶體位於1000，以上程式就會依序輸出1000與0，第二次使用safeFree巨集時傳入NULL值並不會造成程式終止，因為函數會偵測出這個狀況並忽略。

### 函數指標
函數指標是指持有函數位址的指標，讓指標能夠指向函數是C語言中十分重要也十分有用的功能。

以下是沒有參數與傳回值的函數指標，void為傳回型別，foo為函數指標的變數名稱，最後的括號內會放置參數。
```c
void (*foo)();
```

※ 使用函數指標時，程式設計師必須注意傳入參數的正確性，C語言並不會檢查傳入的參數是否正確。

以下是其他的函數指標宣告:
```c
// 傳入double並傳回int
int (*f1)(double); 

// 傳入char指標，沒有回傳值
void (*f2)(char*); 

// 傳入兩個int，傳回double指標
double* (*f3)(int, int);
```

※ 建議將所有的函數指標變數名稱都以fptr開頭

不要混淆傳回指標的函數與函數指標:
```c
// 傳回int指標的函數
int *f4();

// 傳回int的函數指標
int (*f5)();

// 傳回int指標的函數指標
int* (*f6)();
```

顯然f4是個傳回指向整數指標的函數，然而，透過小括號很明確地將表示指標的星號與函數名稱結合在一起，讓它變成函數指標。

### 使用函數指標
以下是個使用函數指標的簡單例子:
```c
int (*fptr1)(int);

int square(int num) {
    return num*num;
}
```

要使用函數指標執行square函數，需要將square函數的位址指派給函數指標，如同陣列名稱，單單使用含述名稱時會傳回函數的位址:
```c
int n = 5;
fptr1 = square;
printf("%d squared is %d\n",n, fptr1(n));
```

輸出結果為:
```shell
5 squared is 25
```

也可以使用取址運算子，淡季沒有必要也太過多餘:
```c
fptr1 = &square;
```

square函數顯示在程式堆疊的下方，這只是畫圖方便，實際上函數是位在記憶體中的另一個區塊而非程式堆疊中。
![Figure 3-10](./Fig/Figure3-10.png)

將函數指標宣告為型別會比較方便，如以下程式宣告了之前店義的函數指標，型別定義看起來有點怪，一般來說，型別定義的名稱是宣告的最後一個元素:
```c
typedef int (*funcptr)(int);
...
funcptr fptr2;
fptr2 = square;
printf("%d squared is %d\n",n, fptr2(n));
```

### 傳入函數指標
傳入函數指標十分容易，只要在函數宣告參數的部分使用函數指標的宣告即可
```c
int add(int num1, int num2) {
return num1 + num2;
}
int subtract(int num1, int num2) {
return num1 - num2;
}
typedef int (*fptrOperation)(int,int);
int compute(fptrOperation operation, int num1, int num2) {
    return operation(num1, num2);
}
```

上面函數的使用方式如下:
```c
printf("%d\n",compute(add,5,6));  // 輸出11
printf("%d\n",compute(sub,5,6));  // 輸出-1
```

add與sub函數的位址傳入了compute函數，這些位址用來呼叫對應的運算

### 傳回函數指標
要傳回函數指標必須將函數的傳回值宣告為函數指標，為了示範這個功能，將重複使用之前的add與sub函數以及型別宣告。下述的select函數會根據輸入的字元傳回對應的函數指標，依據opcode傳回add或sub函數的指標。
```c
fptrOperation select(char opcode) {
    switch(opcode) {
        case '+': return add;
        case '-': return subtract;
    }
}
```

以下的evaluate函數將之前的範例合而為一，函數需要兩個整數與一個表示需要執行的運算字元，將opcode傳入select函數，取得對應要執行的函數指標，在return命令中，執行函數並傳回結果:
```c
int evaluate(char opcode, int num1, int num2) {
    fptrOperation operation = select(opcode);
    return operation(num1, num2);
}
```

以下是函數的使用範例:
```c
printf("%d\n",evaluate('+', 5, 6));  // 輸出11
printf("%d\n",evaluate('-', 5, 6));  // 輸出-1
```

### 使用函數指標的範例
使用函數指標陣列可以依據條件選擇對應執行的函數，陣列的宣告十分直覺，只要把函數指標的宣告作為陣列的型別就好，以下範例將陣列中的元素都初始化為NULL，使用初始值區塊初始化陣列時，會將所有元素填滿相同數值，因此範例陣列中剩下的其他元素都會初始化為NULL:
```c
typedef int (*operation)(int, int);
operation operations[128] = {NULL};
```

不使用typedef指令可以寫成如以下的形式:
```c
int (*operations[128])(int, int) = {NULL};
```

目的是希望能利用字元作為索引選擇對應執行的函數。例如，當對應的乘法函數存在時，「*」字元會執行乘法函數，能使用自元作為索引的原因在於字元是整數值，陣列的128個位置分別對應到128個ASCII字元，接下來將結合以上的陣列宣告以及上一節中的add與sub函數。

將陣列初始化為NULL之後，接下來將add與sub函數與對應的加法、減法字元結合:
```c
void initializeOperationsArray() {
    operations['+'] = add;
    operations['-'] = subtract;
}
```

將之前的evaluate函數改寫成evaluateArray，直接使用operations搭配operation字元作為索引，不再透過select函數取得對應的函數指標:
```c
int evaluateArray(char opcode, int num1, int num2) {
    fptrOperation operation;
    operation = operations[opcode];
    return operation(num1, num2);
}
```

以下測試程式:
```c
initializeOperationsArray();
printf("%d\n",evaluateArray('+', 5, 6));  // 輸出11
printf("%d\n",evaluateArray('-', 5, 6));  // 輸出-1
```

要使evaluateArray函數更安全，應該在執行函數前先檢查函數指標是否為NULL。

### 比較函數指標
函數指標可以比較是否相等:

add函數指派給ftpr1函數指標，再與add函數的位址比較
```c
fptrOperation fptr1 = add;
if(fptr1 == add) {
    printf("fptr1 points to add function\n");
} else {
    printf("fptr1 does not point to add function\n");
}
```

執行時可以從輸出看出指標指向add函數。

### 函數指標轉型
函數指標能夠轉型成其他型別，使用上要十分小心，執行期環境不會檢查轉型前後是否一致。也可以將函數指標轉型為其他型別後再轉回來原來的型別，最後的結果應該與原先的指標相等。以下是轉型的例子:
```c
typedef int (*fptrToSingleInt)(int);
typedef int (*fptrToTwoInts)(int,int);
int add(int, int);
fptrToTwoInts fptrFirst = add;
fptrToSingleInt fptrSecond = (fptrToSingleInt)fptrFirst;
fptrFirst = (fptrToTwoInts)fptrSecond;
printf("%d\n",fptrFirst(5,6));  // 輸出11
```

※ 函數指標與資料指標間的轉換不保證一定能成功。

void* 不一定能夠與函數指標一同使用，也就是不該如以下程式將函數指派給void*指標:
```c
void* pv = add;
```

在互換函數指標時常會看到某個「基本」函數指標型別，宣告方式如下，fptrBase是個指向參數與傳回值都是void的函數指標。
```c
typedef void (*fptrBase)();
```

以下是基本指標的使用方式:
```c
fptrBase basePointer;
fptrFirst = add;
basePointer = (fptrToSingleInt)fptrFirst;
fptrFirst = (fptrToTwoInts)basePointer;
printf("%d\n",fptrFirst(5,6));
```

基本指標是交換函數指標時的暫存變數。

※ 每次都要小心檢查函數指標的參數列正確，否則會造成無法預期的行為。