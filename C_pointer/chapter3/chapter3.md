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