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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        
        vector<int> left = postorderTraversal(root->left);
        ans.insert(ans.end(), left.begin(), left.end());

        vector<int> right = postorderTraversal(root->right);
        ans.insert(ans.end(), right.begin(), right.end());

        ans.push_back(root->val);

        return ans;
    }
};

int main(void)
{
    int data;
    queue<TreeNode *> q;

    TreeNode *root, *cur;
    cin >> data;
    if(data != NULLTOKEN)
    {
        root = new TreeNode(data); 
        cur = root;

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
                cur->left = right_node;
                q.push(right_node);
            }

            cur = q.front();
            q.pop();
        }
    }
    else
        root = NULL;
    
    Solution sol;
    vector<int> ans = sol.postorderTraversal(root);

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