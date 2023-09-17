#include<stdlib.h>
#include "myArray.h"

// Initialize
void my_array_initialize(myArr* arr, int length)
{
    arr->data = (int*)malloc(sizeof(int) * length);
    
    if(arr)
        arr->length = length;
    else
        printf("My array initialization failed!\n");

    arr->count = 0;
}

// Append
void my_array_append(myArr* arr, int data)
{
    if(my_array_is_full(arr))
    {
        printf("My array is full, it can't append more data!\n");
        return;
    }

    arr->data[arr->count] = data;
    arr->count++;
}

// Delete
void my_array_delete(myArr* arr)
{
    if(my_array_is_empty(arr))
    {
        printf("My array is empty, it can't delete any data!\n");
        return;
    }

    arr->count--;
}

// Insert
void my_array_insert(myArr* arr, int data, int index)
{
    if(my_array_is_full(arr))
    {
        printf("My array is full, it can't insert more data!\n");
        return;
    }

    if((index < 1) || (index > arr->count + 1))
    {
        printf("Index %d can't be inserted!\n", index);
        return;
    }

    for(int i = arr->count - 1; i >= index - 1; --i)
        arr->data[i + 1] = arr->data[i];

    arr->data[index] = data;
    arr->count += 1;
    return;
}

// Display
void my_array_display(myArr* arr)
{
    if(my_array_is_empty(arr))
    {
        printf("My array is empty, it can't display any data!\n");
        return;
    }

    for(int i = 0; i < arr->count; ++i)
        printf("%d ", arr->data[i]);
    printf("\n");
}

// Is empty
_Bool my_array_is_empty(myArr* arr)
{
    return (arr->count == 0);
}

// Is full
_Bool my_array_is_full(myArr* arr)
{
    return (arr->count == arr->length);
}