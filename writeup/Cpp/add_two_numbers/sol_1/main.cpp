#include<iostream>
#include<string>
#include<sstream>

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
    string data;

    getline(cin, data);
    ListNode *l1 = new ListNode();
    ListNode *cur = l1;
    stringstream s1(data);
    string nums;
    while(getline(s1, nums, ' '))
    {
        ListNode *temp = new ListNode(stoi(nums));
        cur->next = temp;
        cur = cur->next;
    }

    getline(cin, data);
    ListNode *l2 = new ListNode();
    cur = l2;
    stringstream s2(data);
    while(getline(s2, nums, ' '))
    {
        ListNode *temp = new ListNode(stoi(nums));
        cur->next = temp;
        cur = cur->next;
    }

    Solution sol;
    ListNode *ans = sol.addTwoNumbers(l1->next, l2->next);
    while(ans->next != NULL)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << ans->val << endl;

    return 0;
}