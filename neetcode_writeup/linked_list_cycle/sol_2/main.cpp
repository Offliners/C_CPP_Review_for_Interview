#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow)
                return true;
        }

        return false;
    }
};


int main(void)
{
    int pos;
    cin >> pos;

    int data;
    int count = 0;
    bool cycle_exist = false;
    ListNode *head = new ListNode(0);
    ListNode *temp = head;
    ListNode *node;
    while(cin >> data)
    {
        temp->next = new ListNode(data);

        if(count == pos)
        {
            node = temp->next;
            cycle_exist = true;
        }

        temp = temp->next;
        ++count;
    }

    if(cycle_exist)
        temp->next = node;

    Solution sol;
    if(sol.hasCycle(head->next))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}