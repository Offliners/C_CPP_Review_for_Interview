#include<iostream>
#include<vector>
#include<climits>

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
    ListNode* middleNode(ListNode* head) {
        if(!head)
            return NULL;
        
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};


int main(void)
{
    int data;
    ListNode *head = new ListNode();
    ListNode *cur = head;
    while(cin >> data)
    {
        cur->next = new ListNode(data);
        cur = cur->next;
    }
    head = head->next;

    Solution sol;
    ListNode *ans = sol.middleNode(head);
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