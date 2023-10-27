#include<stdio.h>
#include<stdlib.h>

void rotate(int* nums, int numsSize, int k){
    int *temp = (int *)malloc(numsSize * sizeof(int));

    for(int i = 0; i < numsSize; ++i)
        temp[(i + k) % numsSize] = nums[i];

    for(int i = 0; i < numsSize; ++i)
        nums[i]= temp[i];

    free(temp);
}

int main(void)
{
    int k, temp;
    temp = scanf("%d", &k);

    int numsSize;
    temp = scanf("%d", &numsSize);

    int *nums = (int *)malloc(numsSize * sizeof(int));
    for(int i = 0; i < numsSize; ++i)
        temp = scanf("%d", &nums[i]);

    rotate(nums, numsSize, k);

    for(int i = 0; i < numsSize - 1; ++i)
        printf("%d ", nums[i]);
    
    printf("%d\n", nums[numsSize - 1]);

    free(nums);

    return 0;
}