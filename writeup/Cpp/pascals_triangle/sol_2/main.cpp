#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0)
            return {{}};

        if(numRows == 1)
            return {{1}};

        vector<vector<int>> prevRow = generate(numRows - 1);
        vector<int> row(numRows, 1);
        for(int i = 1; i < numRows - 1; ++i)
            row[i] = prevRow.back()[i - 1] + prevRow.back()[i];

        prevRow.push_back(row);
        return prevRow;
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