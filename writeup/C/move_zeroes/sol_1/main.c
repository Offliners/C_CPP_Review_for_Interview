#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void moveZeroes(int* nums, int numsSize){
    int slow = 0;

    for(int i = 0; i < numsSize; ++i)
    {
        if(nums[i] != 0 && nums[slow] == 0)
            swap(&nums[i], &nums[slow]);

        if(nums[slow] != 0)
            ++slow;
    }
}

int main()
{
    int len, temp;
    temp = scanf("%d\n", &len);

    int *nums = (int*)malloc(len * sizeof(int));
    for(int i = 0; i < len; ++i)
        temp = scanf("%d", &nums[i]);

    moveZeroes(nums, len);

    for(int i = 0; i < len - 1; ++i)
        printf("%d ", nums[i]);
    printf("%d\n", nums[len - 1]);

    free(nums);

    return 0;
}