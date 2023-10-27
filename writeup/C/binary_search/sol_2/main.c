#include<stdio.h>
#include<stdlib.h>

int search(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize - 1;

    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] > target)
            right = mid - 1;
        else if(nums[mid] < target)
            left = mid + 1;
        else
            return mid;
    }

    return -1;
}

int main(void)
{
    int temp;
    int target;
    temp = scanf("%d", &target);

    int len;
    temp = scanf("%d", &len);

    int *nums = (int*)malloc(len * sizeof(int));
    for(int i = 0; i < len; ++i)
        temp = scanf("%d", &num);

    printf("%d\n", search(nums, len, target));

    free(nums);

    return 0;
}