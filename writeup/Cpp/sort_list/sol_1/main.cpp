#include<iostream>
#include<vector>
#include<algorithm>

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
    ListNode* sortList(ListNode* head) {
        if(!head)
            return NULL;

        vector<int> arr;

        ListNode* cur = head;
        while(cur)
        {
            arr.push_back(cur->val);
            cur = cur->next;
        }

        sort(arr.begin(), arr.end());
        ListNode* ans = new ListNode();
        cur = ans;
        for(int i = 0; i < arr.size(); ++i)
        {
            ListNode *temp = new ListNode(arr[i]);
            cur->next = temp;
            cur = cur->next;
        }

        return ans->next;
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
    ListNode *ans = sol.sortList(head->next);
    if(!ans)
        return 0;

    while(ans->next)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }

    cout << ans->val << endl;

    return 0;
}