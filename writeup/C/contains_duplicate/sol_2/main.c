#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int front, int end)
{
    int pivot = arr[end];
    int i = front - 1;
    for(int j = front; j < end; ++j)
    {
        if(arr[j] < pivot)
        {
            ++i;
            swap(&arr[i], &arr[j]);
        }
    }

    ++i;
    swap(&arr[i], &arr[end]);

    return i;
}

void quick_sort(int *arr, int front, int end)
{
    if(front < end)
    {
        int pivot = partition(arr, front ,end);
        quick_sort(arr, front, pivot - 1);
        quick_sort(arr, pivot + 1, end);
    }
}

_Bool containsDuplicate(int* nums, int numsSize){
    quick_sort(nums, 0, numsSize - 1);

    for(int i = 0; i < numsSize - 1; ++i)
        if(nums[i] == nums[i + 1])
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