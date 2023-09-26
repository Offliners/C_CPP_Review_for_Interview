#include<stdio.h>
#include"myLinkedList.h"

int main(void)
{
    node linked_list;

    my_linked_list_initialize(&linked_list);

    my_linked_list_append(&linked_list, 1);
    my_linked_list_append(&linked_list, 5);

    my_linked_list_display(&linked_list);
    return 0;
}