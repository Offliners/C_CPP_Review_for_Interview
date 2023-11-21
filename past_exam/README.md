# 考古題
## Bitwise Operation
### Set a bit
```c
#include<stdio.h>
#include<stdlib.h>

unsigned int set_bit(unsigned int x, int bit_num)
{
    x |= (1 << bit_num);
    return x;
}

int main(void)
{
    unsigned int a = 0x1000;           // 0001 0000 0000 0000
    printf("%x\n", set_bit(a, 2));     // 0001 0000 0000 0100
    printf("%x\n", set_bit(a, 1));     // 0001 0000 0000 0010

    return 0;
}
```

### Clear a bit
```c
#include<stdio.h>
#include<stdlib.h>

unsigned int clear_bit(unsigned int x, int bit_num)
{
    x &= ~(1 << bit_num);
    return x;
}

int main(void)
{
    unsigned int a = 0xFFFF;             // 1111 1111 1111 1111
    printf("%x\n", clear_bit(a, 2));     // 1111 1111 1111 1011
    printf("%x\n", clear_bit(a, 1));     // 1111 1111 1111 1101

    return 0;
}
```

### Toggle a bit
```c
#include<stdio.h>
#include<stdlib.h>

unsigned int toggle_bit(unsigned int x, int bit_num)
{
    x ^= (1 << bit_num);
    return x;
}

int main(void)
{
    unsigned int a = 0x0005;              // 0000 0000 0000 0101
    printf("%x\n", toggle_bit(a, 2));     // 0000 0000 0000 0001
    printf("%x\n", toggle_bit(a, 1));     // 0000 0000 0000 0111

    return 0;
}
```

### 判斷數值中含有幾個1
```c
#include<stdio.h>
#include<stdlib.h>

int calc_number_1(unsigned int x)
{
    int count = 0;
    
    while(x)
    {
        x &= (x - 1);
        ++count;
    }
    
    return count;
}

int main(void)
{
    unsigned int a = 0xFFFF;            // 1111 1111 1111 1111
    printf("%d\n", calc_number_1(a));   // 16
    
    unsigned int b = 0x8888;            // 1000 1000 1000 1000
    printf("%d\n", calc_number_1(b));   // 4

    return 0;
}
```

### 判斷數值是否為2的n次方數
```c
#include<stdio.h>
#include<stdlib.h>

int calc_number_1(unsigned int x)
{
    int count = 0;
    
    while(x)
    {
        x &= (x - 1);
        ++count;
    }
    
    return count;
}

int is_2_power(unsigned int x)
{   
    return calc_number_1(x) == 1;
}

int main(void)
{
    unsigned int a = 256;
    printf("%d\n", is_2_power(a));   // 1: true
    
    unsigned int b = 123;
    printf("%d\n", is_2_power(b));   // 0: false

    return 0;
}
```

### 取數值中最高位元的位置
```c
#include<stdio.h>
#include<stdlib.h>

int get_highest_bit(unsigned int x)
{
    unsigned int test = 0xFFFF;
    int count = 15; // number of test bit - 1
    
    while(((x & test) >> count) != 1)
    {
        test >>= 1;
        --count;
    }
    
    return count;
}

int main(void)
{
    unsigned int a = 0x7A9B;              // 0111 1010 1001 1011
    printf("%d\n", get_highest_bit(a));   // 14
    
    unsigned int b = 0x0080;              // 0000 0000 1000 0000
    printf("%d\n", get_highest_bit(b));   // 7

    return 0;
}
```

### 取數值中最低位元的位置
```c
#include<stdio.h>
#include<stdlib.h>

int get_highest_bit(unsigned int x)
{
    unsigned int test = 0xFFFF;
    int count = 15; // number of test bit - 1
    
    while(((x & test) >> count) != 1)
    {
        test >>= 1;
        --count;
    }
    
    return count;
}

int get_lowest_bit(unsigned int x)
{
    x &= (-x);
    return get_highest_bit(x);
}

int main(void)
{
    unsigned int a = 0x7A9B;             // 0111 1010 1001 1011
    printf("%d\n", get_lowest_bit(a));   // 0
    
    unsigned int b = 0x0080;             // 0000 0000 1000 0000
    printf("%d\n", get_lowest_bit(b));   // 7

    return 0;
}
```