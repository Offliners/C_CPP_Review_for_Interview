#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> prevRow;
        
        for(int i = 0; i < numRows; ++i)
        {
            vector<int> currentRow(i + 1, 1);
            
            for(int j = 1; j < i; ++j)
                currentRow[j] = prevRow[j - 1] + prevRow[j];
            
            result.push_back(currentRow);
            prevRow = currentRow;
        }
        
        return result;
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