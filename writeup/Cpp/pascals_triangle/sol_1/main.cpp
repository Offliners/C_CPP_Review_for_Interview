#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1; i <= numRows; ++i)
        {
            vector<int> row;
            row.push_back(1);

            for(int j = 2; j <= i - 1; ++j)
                row.push_back(ans[i - 2][j - 2] + ans[i - 2][j - 1]);

            if(i != 1)
                row.push_back(1);

            ans.push_back(row);
        }

        return ans;
    }
};

int main(void)
{
    Solution sol;
    int num;
    vector<vector<int>> ans;

    cin >> num;

    ans = sol.generate(num);
    for(int i = 0; i < ans.size(); ++i)
    {
        for(int j = 0; j < ans[i].size() - 1; ++j)
            cout << ans[i][j] << " ";

        cout << ans[i][ans[i].size() - 1] << endl;
    }

    return 0;
}