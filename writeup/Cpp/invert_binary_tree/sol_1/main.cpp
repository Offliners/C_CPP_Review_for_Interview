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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return NULL;
        
        invertTree(root->left);
        invertTree(root->right);

        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;

        return root;
    }
};

void flatten_tree(vector<int>& data, TreeNode *root)
{
    if(root)
    {
        data.push_back(root->val);
        flatten_tree(data, root->left);
        flatten_tree(data, root->right);
    }
}

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
    TreeNode *ans = sol.invertTree(root);

    vector<int> flatten;
    flatten_tree(flatten, root);
    
    if(flatten.size() == 0)
    {
        cout << endl;
        return 0;
    }

    for(int i = 0; i < flatten.size() - 1; ++i)
        cout << flatten[i] << " ";
    cout << flatten.back() << endl;

    return 0;
}