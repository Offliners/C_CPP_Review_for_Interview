#include<stdio.h>
#include<stdlib.h>

int mySqrt(int x){
    if(x == 0 || x == 1)
        return x;

    int front = 1;
    int end = x;
    while(front <= end)
    {
        int mid = front + (end - front) / 2;
        if(mid > x / mid)
            end = mid - 1;
        else if(mid < x / mid)
            front = mid + 1;
        else
            return mid;
    }

    return end;
}


int main(void)
{
    int x, temp;
    temp = scanf("%d", &x);

    printf("%d\n", mySqrt(x));

    return 0;
}