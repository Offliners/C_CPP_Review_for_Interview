#include<iostream>

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
    ListNode* reverseList(ListNode* head) {
        if(!head || !(head->next))
            return head;
        
        ListNode *root = reverseList(head->next);
        
        head->next->next = head;
        head->next = NULL;

        return root;
    }
};

int main(void)
{
    int data;
    ListNode *link_list = new ListNode();
    ListNode *l = link_list;

    Solution sol;

    while(cin >> data)
    {
        l->next = new ListNode(data);
        l = l->next;
    }

    ListNode *ans = sol.reverseList(link_list->next);

    if(!ans)
        return 0;

    while(ans->next != NULL)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << ans->val << endl;

    return 0;
}