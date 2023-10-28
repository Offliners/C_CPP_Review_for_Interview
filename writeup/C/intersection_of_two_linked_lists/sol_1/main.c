#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *tempA = headA;
    struct ListNode *tempB = headB;

    while(tempA != tempB)
    {
        tempA = (tempA) ? tempA->next : headB;
        tempB = (tempB) ? tempB->next : headA;
    }

    return tempA;
}

int main(void)
{
    int skipA, temp;
    temp = scanf("%d", &skipA);

    int lenA;
    temp = scanf("%d", &lenA);

    struct ListNode *headA = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *intersection = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *cur = headA;
    for(int i = 0; i < lenA; ++i)
    {
        temp = scanf("%d", &cur->val);
        struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        cur->next = temp;
        
        if(i == skipA)
            intersection = cur;

        cur = cur->next;
    }

    int skipB;
    temp = scanf("%d", &skipB);

    int lenB;
    temp = scanf("%d", &lenB);

    struct ListNode *headB = (struct ListNode *)malloc(sizeof(struct ListNode));
    cur = headB;
    for(int i = 0; i < lenB; ++i)
    {
        temp = scanf("%d", &cur->val);

        if(i == skipB)
        {
            cur->next = intersection;
            break;
        }

        struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        cur->next = temp;
        cur = cur->next;
    }

    struct ListNode *ans = getIntersectionNode(headA, headB);
    if(!ans)
        printf("No intersection\n");
    else
        printf("Intersected at \'%d\'\n", ans->val);

    struct ListNode *tmp_ptr;
    while(ans)
    {
        tmp_ptr = ans;
        ans = ans->next; 
        free(tmp_ptr);
    }

    while(headA)
    {
        tmp_ptr = headA;
        headA = headA->next; 

        if(headA)
        {
            free(headA);
            break;
        }
    }

    while(headB)
    {
        tmp_ptr = headB;
        headB = headB->next; 

        if(headB)
        {
            free(headB);
            break;
        }
    }

    return 0;
}