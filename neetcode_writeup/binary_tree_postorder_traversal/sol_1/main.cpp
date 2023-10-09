#include<iostream>
#include<vector>
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
    vector<int> num;

    while(cin >> data)
        num.push_back(data);

    int null_token = NULLTOKEN;
    TreeNode *root = new TreeNode();
    if(num.front() != null_token)
    {
        root->val = num.front();
        TreeNode *cur = root;
        for(int i = 1; i < num.size(); ++i)
        {
            TreeNode *left_node = new TreeNode(num[i]);
            if(num[i] == null_token)
                left_node = NULL;

            cur->left = left_node;

            if(i + 1 > num.size() - 1)
                break;

            ++i;
            TreeNode *right_node = new TreeNode(num[i]);
            if(num[i] == null_token)
                right_node = NULL;
            
            cur->right = right_node;

            if(cur->left)
                cur = cur->left;
            else if(cur->right)
                cur = cur->right;
            else
                break;
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