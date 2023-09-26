#include<stdio.h>

typedef struct Node {
    int data;
    struct Node* next; 
} node;

// Initialize
void my_linked_list_initialize(node* head);

// Append
void my_linked_list_append(node* head, int data);

// Remove
void my_linked_list_remove(node* head);

// Insert
void my_linked_list_insert(node* head, int data, int index);

// Delete
void my_linked_list_delete(node* head, int index);

// Display
void my_linked_list_display(node* head);