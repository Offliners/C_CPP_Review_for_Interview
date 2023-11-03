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
        if(!head)
            return NULL;

        ListNode *cur = head;
        int count = 0;
        while(cur)
        {
            ++count;
            cur = cur->next;
        }

        ListNode *dummy = new ListNode();
        dummy->next = head;
        for(int i = 0; i < count; ++i)
        {
            ListNode *top = dummy;
            for(int j = i + 1; j < count; ++j)
            {
                ListNode *cur = top->next;
                ListNode *nxt = cur->next;
                if(nxt->val < cur->val)
                {
                    ListNode *temp = nxt->next;   
                    top->next = nxt;
                    nxt->next = cur;
                    cur->next = temp;
                }
                top = top->next;
            }
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