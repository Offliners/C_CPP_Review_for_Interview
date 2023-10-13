# Chatper 2 - C語言的動態記憶體管理
## 動態記憶體配置
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