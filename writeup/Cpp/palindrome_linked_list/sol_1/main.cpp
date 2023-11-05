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
    bool isPalindrome(ListNode* head) {
        ListNode *cur = head;
        vector<int> nums;

        while(cur)
        {
            nums.push_back(cur->val);
            cur = cur->next;
        }

        for(int i = 0; i < nums.size() / 2; ++i)
            if(nums[i] != nums[nums.size() - 1 - i])
                return false;

        return true;
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
    if(sol.isPalindrome(head->next))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}