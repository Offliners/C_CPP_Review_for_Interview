#include<stdlib.h>
#include"myLinkedList.h"

// Initialize
void my_linked_list_initialize(node* head)
{
    head->data = -1;
    head->next = NULL;
}

// Append
void my_linked_list_append(node* head, int data)
{
    if(my_linked_list_is_empty(head))
    {
        head->data = data;
        head->next = NULL;
    }
    else
    {
        for(node* current = head; current; current = current->next)
        {
            if(current->next == NULL)
            {
                node* n = (node*)malloc(sizeof(node));
                n->data = data;
                n->next = NULL;
                current->next = n;
                return;
            }
        }
    }
}

// Remove
void my_linked_list_remove(node* head)
{
    if(my_linked_list_is_empty(head))
    {
        printf("My array is empty, it can't remove any data!\n");
        return;
    }

    for(node* current = head; current; current = current->next)
    {
        if(current->next->next == NULL)
        {
            current->next = NULL;
            return;
        }
    }
}

// Insert
void my_linked_list_insert(node* head, int data, int index)
{
    int i = 0;
    for(node* current = head; current; current = current->next)
    {
        if(i == index - 1)
        {
            node* n = (node*)malloc(sizeof(node));
            n->data = data;
            n->next = current->next;
            current->next = n;
            return;
        }

        ++i;
    }

    printf("Index %d can't be appended!\n", index);
}

// Delete
void my_linked_list_delete(node* head, int index)
{
    if(my_linked_list_is_empty(head))
    {
        printf("My array is empty, it can't delete any data!\n");
        return;
    }

    int i = 0;
    for(node* current = head; current; current = current->next)
    {
        if(i == index - 1)
        {
            current->next = current->next->next;
            return;
        }

        ++i;
    }

    printf("Index %d can't be deleted!\n", index);
}

// Display
void my_linked_list_display(node* head)
{
    if(my_linked_list_is_empty(head))
    {
        printf("My linked list is empty, it can't display any data!\n");
        return;
    }

    for(node* current = head; current; current = current->next)
        printf("%d -> ", current->data);

    printf("NULL\n");
}

// Is empty
_Bool my_linked_list_is_empty(node* head)
{
    return (head->data == -1);
}