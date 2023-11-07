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
        if(!head)
            return NULL;

        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *temp = dummy;
        while(temp && temp->next)
        {
            ListNode *next = NULL;
            ListNode *cur = temp;
            while(cur && cur->next)
            {
                if(cur->next->val != val)
                {
                    next = cur->next;
                    break;
                }

                cur = cur->next;
            }
            temp->next = next;
            temp = temp->next;
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