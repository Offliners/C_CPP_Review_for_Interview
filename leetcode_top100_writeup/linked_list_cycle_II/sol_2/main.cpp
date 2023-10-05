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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        bool find_cycle = false;
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow)
            {
                find_cycle = true;
                break;
            }
        }

        if(!find_cycle)
            return NULL;

        slow = head;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
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
    ListNode *cycle = sol.detectCycle(head->next);

    if(!cycle)
    {
        cout << "no cycle" << endl;
        return 0;
    }

    count = 0;
    temp = head->next;
    while(temp)
    {
        if(cycle->next == temp->next)
            break;
        
        ++count;
        temp = temp->next;
    }

    cout << "tail connects to node index " << count << endl;

    return 0;
}