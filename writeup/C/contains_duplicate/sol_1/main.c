#include<stdio.h>
#include<stdlib.h>

_Bool containsDuplicate(int* nums, int numsSize){
    for(int i = 0; i < numsSize; ++i)
        for(int j = i + 1; j < numsSize; ++j)
            if(nums[i] == nums[j])
                return 1;

    return 0;
}

int main(void)
{
    int len, temp;
    temp = scanf("%d", &len);

    int *nums = (int*)malloc(len * sizeof(int));
    for(int i = 0; i < len; ++i)
        temp = scanf("%d", &nums[i]);

    if(containsDuplicate(nums, len))
        printf("true\n");
    else
        printf("false\n");

    free(nums);

    return 0;
}