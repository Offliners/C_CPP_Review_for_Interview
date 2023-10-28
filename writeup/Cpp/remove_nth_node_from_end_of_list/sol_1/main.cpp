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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;

        int count = 0;
        while(temp)
        {
            temp = temp->next;
            ++count;
        }

        if(count == 1)
            return NULL;

        if(n == count)
            return head->next;

        temp = head;
        for(int i = 0; i < count; ++i)
        {
            if(i == count - n - 1)
            {
                if(!temp->next->next)
                    temp->next = NULL;
                else
                    temp->next = temp->next->next;
                break;
            }

            temp = temp->next;
        }

        return head;
    }
};


int main(void)
{
    int n, data;
    cin >> n;

    ListNode *head = new ListNode();
    ListNode *cur = head;
    while(cin >> data)
    {
        ListNode *temp = new ListNode(data);
        cur->next = temp;
        cur = cur->next;
    }

    Solution sol;
    ListNode *ans = sol.removeNthFromEnd(head->next, n);

    if(!ans)
    {
        cout << endl;
        return 0;
    }

    while(ans)
    {
        cout << ans->val;

        if(!ans->next)
            cout << endl;
        else
            cout << " ";

        ans = ans->next;
    }

    return 0;
}