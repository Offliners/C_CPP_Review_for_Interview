#include<stdio.h>
#include<stdlib.h>

_Bool isPowerOfTwo(int n){
    return (n > 0) && (n & (n - 1) == 0);
}

int main(void)
{
    int n, temp;
    temp = scanf("%d", &n);

    if(isPowerOfTwo(n))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}