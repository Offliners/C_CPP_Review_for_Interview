#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
    if(!head)
        return  NULL;
    
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    int find_cycle = 0;
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
        {
            find_cycle = 1;
            break;
        }
    }

    if(!find_cycle)
        return NULL;
    
    slow = head;
    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return  slow;
}

int main(void)
{
    int has_cycle, temp;
    temp = scanf("%d", &has_cycle);

    int list_len;
    temp = scanf("%d", &list_len);

    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *cur = head;
    struct ListNode *cycle;
    if(has_cycle != -1)
    {
        for(int i = 0; i < list_len; ++i)
        {
            temp = scanf("%d", &cur->val);
            struct ListNode *next = (struct ListNode *)malloc(sizeof(struct ListNode));
            cur->next = next;
            cur = cur->next;

            if(i == has_cycle)
                cycle = next;
        }

        cur->next = cycle;
    }

    struct ListNode *pos = detectCycle(head);
    if(pos == cycle)
        printf("tail connects to node index %d\n", has_cycle);
    else
        printf("no cycle\n");

    struct ListNode *temp_ptr;
    cur->next = NULL;
    while(head)
    {
        temp_ptr = head;
        head = head->next;
        free(temp_ptr);
    }

    return 0;
}