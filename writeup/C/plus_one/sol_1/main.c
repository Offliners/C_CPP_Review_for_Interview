#include<stdio.h>
#include<stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *temp = (int*)malloc(digitsSize * sizeof(int));

    int carry = 1;
    for(int i = digitsSize - 1; i >= 0; --i)
    {
        int sum = digits[i] + carry;
        temp[i] = sum % 10;
        carry = sum / 10;
    }
    
    if(carry)
    {
        *returnSize = digitsSize + 1;
        int *ans = (int*)malloc(*returnSize * sizeof(int));
        ans[0] = carry;
        for(int i = 1; i < *returnSize; ++i)
            ans[i] = temp[i - 1];
        
        return ans;
    }
    else
    {
        *returnSize = digitsSize;
        return temp;
    }
}

int main(void)
{
    int digitsSize, returnSize, temp;
    temp = scanf("%d", &digitsSize);

    int *digits = (int*)malloc(digitsSize * sizeof(int));
    for(int i = 0; i < digitsSize; ++i)
        temp = scanf("%d", &digits[i]);

    int *ans = plusOne(digits, digitsSize, &returnSize);
    for(int i = 0; i < returnSize - 1; ++i)
        printf("%d ", ans[i]);
    printf("%d\n", ans[returnSize - 1]);

    free(digits);
    free(ans);

    return 0;
}
