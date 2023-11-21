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
    
    unsigned int b = 0x8888;
    printf("%d\n", calc_number_1(b));   // 4

    return 0;
}
```