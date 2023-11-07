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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode();
        dummy->next = head;

        ListNode *prev = dummy;
        ListNode *cur = head;
        while(cur)
        {
            ListNode *next = cur->next;

            if(cur->val == val)
                prev->next = next;
            else
                prev = cur;

            cur = next;
        }

        return dummy->next;
    }
};


int main(void)
{
    int val, data;
    cin >> val;

    ListNode *head = new ListNode();
    ListNode *cur = head;
    while(cin >> data)
    {
        ListNode *temp = new ListNode(data);
        cur->next = temp;
        cur = cur->next;
    }

    Solution sol;
    ListNode *ans = sol.removeElements(head->next, val);

    if(!ans)
    {
        cout << endl;
        return 0;
    }

    while(ans)
    {
        cout << ans->val;

        if(!ans->next)
            cout << endl;
        else
            cout << " ";

        ans = ans->next;
    }

    return 0;
}