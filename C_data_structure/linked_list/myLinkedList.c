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
    if(head->data == -1)
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
                break;
            }
        }
    }
}

// Remove
void my_linked_list_remove(node* head);

// Insert
void my_linked_list_insert(node* head, int data, int index);

// Delete
void my_linked_list_delete(node* head, int index);

// Display
void my_linked_list_display(node* head)
{
    for(node* current = head; current; current = current->next)
        printf("%d -> ", current->data);

    printf("NULL\n");
}