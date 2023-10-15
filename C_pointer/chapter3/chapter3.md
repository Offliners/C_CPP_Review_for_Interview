## Chatper 3 - 指標與函數
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