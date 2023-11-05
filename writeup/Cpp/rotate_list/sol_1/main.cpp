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
    ListNode* rotateRight(ListNode* head, int k) { 
        if(!head || k == 0)
            return head;

        int count = 1;
        ListNode *cur = head;
        while(cur->next)
        {
            ++count;
            cur = cur->next;
        }
        cur->next = head;
        k %= count;
        k = count - k;

        while(k--)
            cur = cur->next;

        head = cur->next;
        cur->next = NULL;

        return head;
    }
};


int main(void)
{
    int k;
    cin >> k;

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
    ListNode *ans = sol.rotateRight(head->next, k);
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