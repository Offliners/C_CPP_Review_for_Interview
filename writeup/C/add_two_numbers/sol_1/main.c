#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *cur_1 = l1;
    struct ListNode *cur_2 = l2;
    struct ListNode *ans = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *cur_3 = ans;

    int carry = 0;
    while(cur_1 || cur_2 || carry)
    {
        int sum = carry;
        if(cur_1)
        {
            sum += cur_1->val;
            cur_1 = cur_1->next;
        }

        if(cur_2)
        {
            sum += cur_2->val;
            cur_2 = cur_2->next;
        }

        struct ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = sum % 10;
        temp->next = NULL;
        carry = sum / 10;
        cur_3->next = temp;
        cur_3 = cur_3->next;
    }

    return ans->next;
}

int main(void)
{
    int len_1, temp;
    temp = scanf("%d", &len_1);

    struct ListNode *l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *cur = l1;
    for(int i = 0; i < len_1; ++i)
    {
        struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp = scanf("%d", &tmp->val);
        cur->next = tmp;
        cur = cur->next;
    }
    l1 = l1->next;

    int len_2;
    temp = scanf("%d", &len_2);

    struct ListNode *l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    cur = l2;
    for(int i = 0; i < len_2; ++i)
    {
        struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp = scanf("%d", &tmp->val);
        cur->next = tmp;
        cur = cur->next;
    }
    l2 = l2->next;

    struct ListNode *ans = addTwoNumbers(l1, l2);
    while(ans->next)
    {
        printf("%d ", ans->val);
        ans = ans->next;
    }
    printf("%d\n", ans->val);

    struct ListNode *tmp_ptr;
    while(l1)
    {
        tmp_ptr = l1;
        l1 = l1->next;
        free(tmp_ptr);
    }

    while(l2)
    {
        tmp_ptr = l2;
        l2 = l2->next;
        free(tmp_ptr);
    }

    while(ans)
    {
        tmp_ptr = ans;
        ans = ans->next;
        free(tmp_ptr);
    }

    return 0;
}