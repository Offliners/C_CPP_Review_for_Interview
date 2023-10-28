#include<stdio.h>
#include<stdlib.h>

int* getConcatenation(int* nums, int numsSize, int* returnSize){
    *returnSize = 2 * numsSize;
    int *ans = (int*)malloc(*returnSize * sizeof(int));
    for(int i = 0; i < numsSize; ++i)
    {
        ans[i] = nums[i];
        ans[i + numsSize] = nums[i];
    }

    return ans;
}

int main(void)
{
    int len, temp;
    temp = scanf("%d", &len);

    int* nums = (int*)malloc(len * sizeof(int));
    for(int i = 0; i < len; ++i)
        temp = scanf("%d", &nums[i]);

    int returnSize;
    int *ans = getConcatenation(nums, len, &returnSize);
    for(int i = 0; i < returnSize - 1; ++i)
        printf("%d ", ans[i]);

    printf("%d\n", ans[returnSize - 1]);

    free(nums);
    free(ans);

    return 0;
}