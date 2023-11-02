#include<stdio.h>
#include<stdlib.h>

int climbStairs(int n) {
    if(n == 0 || n == 1)
        return 1;
    
    return climbStairs(n - 1) + climbStairs(n - 2);
}

int main(void)
{
    int n, temp;
    temp = scanf("%d", &n);

    printf("%d\n", climbStairs(n));

    return 0;
}