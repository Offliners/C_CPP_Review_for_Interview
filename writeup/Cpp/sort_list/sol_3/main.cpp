#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *half;
        while(fast && fast->next)
        {
            half = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        half->next = NULL;

        ListNode *left = sortList(head);
        ListNode *right = sortList(slow);

        return mergeSort(left, right);
    }

    ListNode* mergeSort(ListNode *left, ListNode *right)
    {
        ListNode *dummy = new ListNode();
        ListNode *cur = dummy;

        while(left && right)
        {
            if(left->val < right->val)
            {
                cur->next = left;
                left = left->next;
            }
            else
            {
                cur->next = right;
                right = right->next;
            }

            cur = cur->next;
        }

        if(left)
        {
            cur->next = left;
            left = left->next;
        }

        if(right)
        {
            cur->next = right;
            right = right->next;
        }

        return dummy->next;
    }
};

int main(void)
{
    int data;
    ListNode *head = new ListNode();
    ListNode *cur = head;
    while(cin >> data)
    {
        ListNode *temp = new ListNode(data);
        cur->next = temp;
        cur = cur->next;
    }

    Solution sol;
    ListNode *ans = sol.sortList(head->next);
    if(!ans)
    {
        cout << endl;
        return 0;
    }

    while(ans->next)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }

    cout << ans->val << endl;

    return 0;
}