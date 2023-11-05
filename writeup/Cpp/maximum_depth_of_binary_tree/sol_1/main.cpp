#include<iostream>
#include<queue>

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
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;

        int depth_left = maxDepth(root->left);
        int depth_right = maxDepth(root->right);

        return max(depth_left, depth_right) + 1;
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
    cout << sol.maxDepth(root) << endl;

    return 0;
}