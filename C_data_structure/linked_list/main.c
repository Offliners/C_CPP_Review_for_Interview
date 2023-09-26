#include<stdio.h>
#include"myLinkedList.h"

void Menu();

int main(void)
{
    int select, data, index;
    node linked_list;

    my_linked_list_initialize(&linked_list);

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
                my_linked_list_append(&linked_list, data);
                break;
            case 2:
                my_linked_list_remove(&linked_list);
                break;
            case 3:
                printf("Please input the index: ");
                scanf("%d", &index);
                printf("Please input the data: ");
                scanf("%d", &data);
                my_linked_list_insert(&linked_list, data, index);
                break;
            case 4:
                printf("Please input the index: ");
                scanf("%d", &index);
                my_linked_list_delete(&linked_list, index);
                break;
            case 5:
                printf("My linked list: ");
                my_linked_list_display(&linked_list);
                break;
            case 6:
                printf("%s", my_linked_list_is_empty(&linked_list) ? "True, my linked list is empty!\n" : "False, my linked list is not empty!\n");
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
    printf("==============================\n");
}