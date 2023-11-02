#include<stdio.h>
#include<stdlib.h>

_Bool isPalindrome(int x) {
    if(x < 0 || (x != 0 && x % 10 == 0))
        return 0;

    long long int rev = 0;
    int temp = x;
    while(temp > 0)
    {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }

    return (x == rev) ? 1 : 0;
}

int main(void)
{
    int x, temp;
    temp = scanf("%d", &x);

    if(isPalindrome(x))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}