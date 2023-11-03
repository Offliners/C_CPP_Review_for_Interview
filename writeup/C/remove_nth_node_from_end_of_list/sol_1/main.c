#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(n == 0)
        return head;

    int count = 0;
    struct ListNode *cur = head;
    while(cur)
    {
        ++count;
        cur = cur->next;
    }

    if(count == n)
        return head->next;

    int index = 0;
    cur = head;
    while(cur)
    {
        if(index == count - n - 1)
            cur->next = cur->next->next;

        ++index;
        cur = cur->next;
    }

    return head;
}

int main(void)
{
    int n, temp;
    temp = scanf("%d", &n);

    int len;
    temp = scanf("%d", &len);

    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *cur = head;
    for(int i = 0; i < len; ++i)
    {
        struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp = scanf("%d", &tmp->val);
        cur->next = tmp;
        cur = cur->next;
    }

    struct ListNode *ans = removeNthFromEnd(head->next, n);
    if(!ans)
    {
        printf("\n");
        return 0;
    }

    while(ans->next)
    {
        printf("%d ", ans->val);
        ans = ans->next;
    }
    printf("%d\n", ans->val);

    struct ListNode *temp_ptr;
    while(head)
    {
        temp_ptr = head;
        head = head->next;
        free(temp_ptr);
    }

    return 0;
}