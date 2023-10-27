#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int reverse(int x){
    long long int reverse = 0;
    while(x)
    {
        reverse = reverse * 10 + x % 10;
        x /= 10;
    }

    return (reverse > INT_MAX) || (reverse < INT_MIN) ? 0 : reverse;
}

int main(void)
{
    int n, temp;
    temp = scanf("%d", &n);

    printf("%d\n", reverse(n));

    return 0;
}