#include<stdio.h>
#include<stdlib.h>

_Bool isPowerOfTwo(int n){
    int res = 0;
    
    while(n > 0)
    {
        res += n % 2;
        n /= 2; 
    }

    return (res == 1);
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