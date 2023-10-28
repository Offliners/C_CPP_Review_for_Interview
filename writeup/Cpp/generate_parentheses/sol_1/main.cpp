#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(ans, n, n, "");

        return ans;
    }

    void dfs(vector<string> &ans, int left, int right, string s)
    {
        if(left > right)
            return;
        
        if(left == 0 && right == 0)
            ans.push_back(s);
        else
        {
            if(left > 0)
                dfs(ans, left - 1, right, s + "(");
            
            if(right > 0)
                dfs(ans, left, right - 1, s + ")");
        }
    }
};

int main(void)
{
    int n;
    cin >> n;

    Solution sol;
    vector<string> ans = sol.generateParenthesis(n);
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << endl;
    
    return 0;
}