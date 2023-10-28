#include<stdio.h>
#include<stdlib.h>

int removeElement(int* nums, int numsSize, int val){
    int k = 0;
    for(int i = 0; i < numsSize; ++i)
    {
        if(nums[i] != val)
        {
            nums[k] = nums[i];
            ++k;
        }
    }

    return k;
}

int main(void)
{
    int val, temp;
    temp = scanf("%d", &val);

    int numsSize;
    temp = scanf("%d", &numsSize);

    int *nums = (int*)malloc(numsSize * sizeof(int));
    for(int i = 0; i < numsSize; ++i)
        temp = scanf("%d", &nums[i]);

    int k = removeElement(nums, numsSize, val);
    printf("%d\n", k);
    if(k > 0)
    {
        for(int i = 0; i < k - 1; ++i)
            printf("%d ", nums[i]);

        printf("%d\n", nums[k - 1]);
    }
    else
        printf("%d\n", nums[0]);


    free(nums);

    return 0;
}