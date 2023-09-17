#include <stdio.h>
#include "myArray.h"

void Menu();

int main(void)
{
    myArr arr;
    int select, length, data, index;

    printf("Please input the length of my array: ");
    scanf("%d", &length);
    my_array_initialize(&arr, length);

    int run = 1;
    while(run)
    {
        Menu();
        printf("Input: ");
        scanf("%d", &select);

        switch(select)
        {
            case 0:
                printf("End!\n");
                run = 0;
                break;
            case 1:
                printf("Please input the data: ");
                scanf("%d", &data);
                my_array_append(&arr, data);
                break;
            case 2:
                my_array_remove(&arr);
                break;
            case 3:
                printf("Please input the index: ");
                scanf("%d", &index);
                printf("Please input the data: ");
                scanf("%d", &data);
                my_array_insert(&arr, data, index);
                break;
            case 4:
                printf("Please input the index: ");
                scanf("%d", &index);
                my_array_delete(&arr, index);
                break;
            case 5:
                printf("My array: ");
                my_array_display(&arr);
                break;
            case 6:
                printf("%s", my_array_is_empty(&arr) ? "True, my array is empty!\n" : "False, my array is not empty!\n");
                break;
            case 7:
                printf("%s", my_array_is_full(&arr) ? "True, my array is full!\n" : "False, my array is not full!\n");
                break;
            default:
                printf("Error input!\n");
                break;
        }
    }

    return 0;
}

void Menu()
{
    printf("====== Menu of My Array ======\n");
    printf("0. Exit\n");
    printf("1. Append\n");
    printf("2. Remove\n");
    printf("3. Insert\n");
    printf("4. Delete\n");
    printf("5. Display\n");
    printf("6. Check empty\n");
    printf("7. Check full\n");
    printf("==============================\n");
}