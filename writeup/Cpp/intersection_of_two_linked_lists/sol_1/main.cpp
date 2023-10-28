#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp = headA;
        int lenA = 0;

        while(temp)
        {
            temp = temp->next;
            ++lenA;
        }

        temp = headB;
        int lenB = 0;
        while(temp)
        {
            temp = temp->next;
            ++lenB;
        }

        if(lenA > lenB)
        {
            while(lenA > lenB)
            {
            headA = headA->next;
            --lenA;
            }
        }
        else if(lenA < lenB)
        {
            while(lenA < lenB)
            {
                headB = headB->next;
                --lenB;
            } 
        }
        
        while(headA && headB)
        {
            if(headA == headB)
                return headA;
            
            headA = headA->next;
            headB = headB->next;
        }

        return NULL;
    }
};


int main(void)
{
    int skipA, lenA;
    cin >> skipA;
    cin >> lenA;

    ListNode *headA = new ListNode(0);
    ListNode *intersection = new ListNode(0);
    ListNode *cur = headA;
    for(int i = 0; i < lenA; ++i)
    {
        int data;
        cin >> data;
        ListNode *temp = new ListNode(data);
        cur->next = temp;
        cur = cur->next;

        if(i == skipA)
            intersection->next = temp;
    }

    int skipB, lenB;
    cin >> skipB;
    cin >> lenB;

    ListNode *headB = new ListNode(0);
    cur = headB;
    for(int i = 0; i < lenB; ++i)
    {
        int data;
        cin >> data;
        ListNode *temp = new ListNode(data);
        cur->next = temp;
        cur = cur->next;

        if(i == skipB)
        {
            cur->next = intersection->next;
            break;
        }
    }

    Solution sol;
    ListNode *ans = sol.getIntersectionNode(headA->next, headB->next);
    if(!ans)
        cout << "No intersection" << endl;
    else
        cout << "Intersected at \'" << ans->val << "\'" << endl;
    
    return 0;
}