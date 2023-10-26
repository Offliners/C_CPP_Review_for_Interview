#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<vector<int>> dp(2, vector<int>(nums.size()));

        dp[0][0] = nums.front();
        dp[1][0] = nums.front();
        for(int i = 1; i < nums.size(); ++i)
        {
            dp[1][i] = max(nums[i], nums[i] + dp[1][i - 1]);
            dp[0][i] = max(dp[0][i - 1], dp[1][i]);
        }

        return dp[0].back();
    }
};

int main(void)
{
    vector<int> nums;
    int data;

    while(cin >> data)
        nums.push_back(data);

    Solution sol;
    cout << sol.maxSubArray(nums) << endl;

    return 0;
}