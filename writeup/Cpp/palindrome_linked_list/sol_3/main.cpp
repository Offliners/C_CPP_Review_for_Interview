#include<iostream>
#include<vector>

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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        if(fast && !fast->next)
            slow = slow->next;

        ListNode *prev = NULL;
        ListNode *next = NULL;
        while(slow && slow->next)
        {
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        if(slow)
            slow->next = prev;

        fast = head;
        while(slow && fast)
        {
            if(slow->val != fast->val)
                return false;

            slow = slow->next;
            fast = fast->next;
        }

        return true;
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
    if(sol.isPalindrome(head->next))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}