#include<iostream>
#include<vector>

#define MINSUM -1e4

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0;
        int max_sum = MINSUM;

        for(int i = 0; i < nums.size(); ++i)
        {
            cur = max(nums[i], cur + nums[i]);
            max_sum = max(max_sum, cur);
        }

        return max_sum;
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