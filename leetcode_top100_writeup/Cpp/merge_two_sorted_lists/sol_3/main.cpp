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

        ListNode *small = new ListNode();
        ListNode *big = new ListNode();

        if(list1->val < list2->val)
        {
            small = list1;
            big = list2;
        }
        else
        {
            small = list2;
            big = list1;
        }

        small->next = mergeTwoLists(small->next, big);

        return small;
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