#include<stdio.h>
#include<stdlib.h>

int singleNumber(int* nums, int numsSize) {
    int ans = nums[0];
    for(int i = 1; i < numsSize; ++i)
        ans ^= nums[i];
    
    return ans;
}

int main(void)
{
    int len, temp;
    temp = scanf("%d", &len);

    int *nums = (int*)malloc(len * sizeof(int));
    for(int i = 0; i < len; ++i)
        temp = scanf("%d", &nums[i]);

    printf("%d\n", singleNumber(nums, len));

    free(nums);

    return 0;
}