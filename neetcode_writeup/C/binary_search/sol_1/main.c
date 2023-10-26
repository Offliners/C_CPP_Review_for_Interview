#include<stdio.h>
#include<stdlib.h>

int search(int* nums, int numsSize, int target){
    for(int i = 0; i < numsSize; ++i)
        if(nums[i] == target)
            return i;
    
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
        temp = scanf("%d", &nums[i]);

    printf("%d\n", search(nums, len, target));

    free(nums);

    return 0;
}