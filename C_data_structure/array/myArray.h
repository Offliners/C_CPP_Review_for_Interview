#include<stdio.h>

typedef struct my_array {
    int* data;
    int length;
    int count;
} myArr;

// Initialize
void my_array_initialize(myArr* arr, int length);

// Append
void my_array_append(myArr* arr, int data);

// Remove
void my_array_remove(myArr* arr);

// Insert
void my_array_insert(myArr* arr, int data, int index);

// Delete
void my_array_delete(myArr* arr, int index);

// Display
void my_array_display(myArr* arr);

// Is empty
_Bool my_array_is_empty(myArr* arr);

// Is full
_Bool my_array_is_full(myArr* arr);