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
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return NULL;
        
        ListNode *prev = NULL;
        ListNode *next;
        while(head)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }
};


int main(void)
{
    int n;
    vector<int> nums;
    ListNode *data = new ListNode();

    Solution sol;

    while(cin >> n)
        nums.push_back(n);

    if(nums.size() > 0)
    {
        int i = 0;
        ListNode *temp = data;
        while(temp && i < nums.size() - 1)
        {
            temp->val = nums[i];
            temp->next = new ListNode();
            temp = temp->next;
            ++i;
        }
        temp->val = nums[nums.size() - 1];
    }
    else
        data = NULL;

    ListNode *ans = sol.reverseList(data);

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