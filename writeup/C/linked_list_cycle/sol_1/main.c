#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

_Bool hasCycle(struct ListNode *head) {
    if(!head || !head->next)
        return 0;

    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
            return 1;
    }

    return 0;
}

int main(void)
{
    int list_len, temp;
    temp = scanf("%d", &list_len);

    int has_cycle;
    temp = scanf("%d", &has_cycle);

    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *cur = head;
    if(has_cycle != -1)
    {
        struct ListNode *cycle;
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

    if(hasCycle(head))
        printf("true\n");
    else
        printf("false\n");

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