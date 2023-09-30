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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        
        if(!list2)
            return list1;

        if(!list1 && !list2)
            return nullptr;

        ListNode *list3 = new ListNode();
        ListNode *l1, *l2, *l3;
        l1 = list1;
        l2 = list2;
        l3 = list3;

        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                l3->next = new ListNode(l1->val);
                l1 = l1->next;
                l3 = l3->next;
            }
            else if(l1->val > l2->val)
            {
                l3->next = new ListNode(l2->val);
                l2 = l2->next;
                l3 = l3->next;
            }
            else
            {
                l3->next = new ListNode(l1->val);
                l1 = l1->next;
                l3 = l3->next;
                l3->next = new ListNode(l2->val);
                l2 = l2->next;
                l3 = l3->next;
            }
        }

        while(l1)
        {
            l3->next = new ListNode(l1->val);
            l1 = l1->next;
            l3 = l3->next;
        }

        while(l2)
        {
            l3->next = new ListNode(l2->val);
            l2 = l2->next;
            l3 = l3->next;
        }

        return list3->next;
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
    int split_link_list_num = -1000;

    Solution sol;

    while(cin >> data)
    {
        if(data == split_link_list_num)
            break;

        val_1->next = new ListNode(data);
        val_1 = val_1->next;
    }

    while(cin >> data)
    {
        if(data == split_link_list_num)
            break;

        val_2->next = new ListNode(data);
        val_2 = val_2->next;
    }

    ListNode *ans = sol.mergeTwoLists(l1->next, l2->next);
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