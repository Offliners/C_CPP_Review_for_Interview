# 考古題
## Bitwise Operation
### Set bit
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

### Clear bit
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