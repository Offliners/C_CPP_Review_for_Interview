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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode();
        ListNode *val_1 = l1;
        ListNode *val_2 = l2;
        ListNode *val_3 = ans;

        int carry = 0;
        while(val_1 != NULL || val_2 != NULL || carry != 0)
        {
            int value = carry;

            if(val_1 != NULL)
            {
                value += val_1->val;
                val_1 = val_1->next;
            }

            if(val_2 != NULL)
            {
                value += val_2->val;
                val_2 = val_2->next;
            }

            carry = value / 10;
            val_3->next = new ListNode(value % 10);
            val_3 = val_3->next;
        }

        return ans->next;
    }
};


int main(void)
{
    int data;
    vector<int> num_1, num_2;
    ListNode *l1 = new ListNode();
    ListNode *val_1 = l1;
    ListNode *l2 = new ListNode();
    ListNode *val_2 = l2;

    Solution sol;

    while(cin >> data)
    {
        num_1.push_back(data);

        if(data == -1)
            break;
    }

    for(int i = 0; i < num_1.size(); ++i)
    {
        if(num_1[i + 1] == -1)
        {
            val_1->val = num_1[i];
            val_1->next = NULL;
            break;
        }
        else
        {
            val_1->val = num_1[i];
            val_1->next = new ListNode();
            val_1 = val_1->next;
        }
    }

    while(cin >> data)
    {
        num_2.push_back(data);

        if(data == -1)
            break;
    }

    for(int i = 0; i < num_2.size(); ++i)
    {

        if(num_2[i + 1] == -1)
        {
            val_2->val = num_2[i];
            val_2->next = NULL;
            break;
        }
        else
        {
            val_2->val = num_2[i];
            val_2->next = new ListNode();
            val_2 = val_2->next;
        }
    }

    ListNode *ans = sol.addTwoNumbers(l1, l2);
    while(ans->next != NULL)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << ans->val << endl;

    return 0;
}