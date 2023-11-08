#include<stdio.h>
#include<stdlib.h>

int searchInsert(int* nums, int numsSize, int target) {
    int front = 0;
    int end = numsSize;

    while(front < end)
    {
        int mid = (front + end) / 2;
        if(nums[mid] < target)
            front = mid + 1;         
        else
            end = mid;
    }

    return front;
}

int main(void)
{
    int target, temp;
    temp = scanf("%d", &target);

    int len;
    temp = scanf("%d", &len);
    int *nums = (int*)malloc(len * sizeof(int));
    for(int i = 0; i < len; ++i)
        temp = scanf("%d", &nums[i]);

    printf("%d\n", searchInsert(nums, len, target));
    free(nums);

    return 0;
}