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
        ListNode *cur = head;
        ListNode *prev = NULL;
        while(cur)
        {
            ListNode *temp = new ListNode(cur->val);
            temp->next = prev;
            prev = temp;
            cur = cur->next;
        }

        cur = head;
        while(prev && cur)
        {
            if(prev->val != cur->val)
                return false;

            prev = prev->next;
            cur = cur->next;
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