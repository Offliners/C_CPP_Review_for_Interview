#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 46

int climbStairs(int n) {
    int *table = (int*)malloc(46 * sizeof(int));
    
    table[0] = 1;
    table[1] = 1;
    for(int i = 2; i <= n; ++i)
        table[i] = table[i - 1] + table[i - 2];

    return table[n];
}

int main(void)
{
    int n, temp;
    temp = scanf("%d", &n);

    printf("%d\n", climbStairs(n));

    return 0;
}