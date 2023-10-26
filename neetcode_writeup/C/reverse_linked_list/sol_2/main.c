#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head){
    if(!head || !head->next)
        return head;

    struct ListNode *root = reverseList(head->next);

    head->next->next = head;
    head->next = NULL;

    return root;
}


int main(void)
{
    int len, temp;
    temp = scanf("%d", &len);

    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *cur = head;

    if(len > 0)
    {
        for(int i = 0; i < len; ++i)
        {
            struct ListNode *next = (struct ListNode *)malloc(sizeof(struct ListNode));
            temp = scanf("%d", &next->val);
            cur->next = next;
            cur = cur->next;
        }
    }
    else
        head = NULL;

    struct ListNode *ans = reverseList(head);
    if(!ans)
        return 0;

    cur = ans;
    while(ans->next->next)
    {
        printf("%d ", ans->val);
        ans = ans->next;
    }
    printf("%d\n", ans->val);

    struct ListNode *temp_ptr;
    while(cur)
    {
        temp_ptr = cur;
        cur = cur->next;
        free(temp_ptr);
    }

    return 0;
}