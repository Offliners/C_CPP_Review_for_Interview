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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> table;
        ListNode *cur = head;
        while(cur != NULL)
        {
            if(table.find(cur) != table.end())
                return true;

            table.insert(cur);
            cur = cur->next;
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