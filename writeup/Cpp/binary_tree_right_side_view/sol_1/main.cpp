#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define NULLTOKEN -101

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};

        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int qsize = q.size();
            int val;
            for(int i = 0; i < qsize; ++i)
            {
                TreeNode *cur = q.front();
                q.pop();
                val = cur->val;
                if(cur->left)
                    q.push(cur->left);
                
                if(cur->right)
                    q.push(cur->right);
            }
            ans.push_back(val);
        }

        return ans;
    }
};

int main(void)
{
    int data;
    queue<TreeNode *> q;

    TreeNode *root;
    cin >> data;
    if(data != NULLTOKEN)
    {
        root = new TreeNode(data); 
        TreeNode *cur = root;

        while(cin >> data)
        {
            if(data != NULLTOKEN)
            {
                TreeNode *left_node = new TreeNode(data);
                cur->left = left_node;
                q.push(left_node);
            }

            if(!(cin >> data))
                break;

            if(data != NULLTOKEN)
            {
                TreeNode *right_node = new TreeNode(data);
                cur->right = right_node;
                q.push(right_node);
            }

            cur = q.front();
            q.pop();
        }
    }
    else
        root = NULL;
    
    Solution sol;
    vector<int> ans = sol.rightSideView(root);

    if(ans.size() != 0)
    {
        for(int i = 0; i < ans.size() - 1; ++i)
            cout << ans[i] << " ";
        cout << ans.back() << endl;
    }
    else
        cout << endl;

    return 0;
}