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
    int diameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;

        dfs(root);

        return diameter;
    }

    int dfs(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        diameter = max(left + right, diameter);

        return max(left, right) + 1;
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
    cout << sol.diameterOfBinaryTree(root) << endl;

    return 0;
}