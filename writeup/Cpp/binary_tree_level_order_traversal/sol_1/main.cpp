#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define NULLTOKEN -1001

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        
        queue<TreeNode*> q;
        vector<vector<int>> ans;

        q.push(root);
        while(!q.empty())
        {
            int qsize = q.size();
            vector<int> nodes;
            for(int i = 0; i < qsize; ++i)
            {
                TreeNode *node = q.front();
                q.pop();

                if(node->left)
                    q.push(node->left);
                
                if(node->right)
                    q.push(node->right);
                
                nodes.push_back(node->val);
            }

            ans.push_back(nodes);
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
    vector<vector<int>> ans = sol.levelOrder(root);

    if(ans.size() != 0)
    {
        for(int i = 0; i < ans.size(); ++i)
        {
            for(int j = 0; j < ans[i].size() - 1; ++j)
                cout << ans[i][j] << " ";
            cout << ans[i].back() << endl;
        }
    }
    else
        cout << endl;

    return 0;
}