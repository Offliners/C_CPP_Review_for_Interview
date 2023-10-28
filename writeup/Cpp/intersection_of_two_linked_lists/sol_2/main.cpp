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
        ListNode *tempA = headA;
        ListNode *tempB = headB;

        while(tempA != tempB)
        {
            tempA = (tempA) ? tempA->next : headB;
            tempB = (tempB) ? tempB->next : headA;
        }

        return tempA;
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