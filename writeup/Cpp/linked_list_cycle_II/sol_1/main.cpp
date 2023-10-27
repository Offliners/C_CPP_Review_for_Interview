#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> table;
        ListNode *cur = head;
        while(cur != NULL)
        {
            if(table.find(cur) != table.end())
                return cur;

            table.insert(cur);
            cur = cur->next;
        }
        
        return NULL;
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