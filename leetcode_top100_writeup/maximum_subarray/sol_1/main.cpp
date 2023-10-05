#include<iostream>
#include<vector>

#define MINSUM -1e4

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = MINSUM;

        for(int i = 0; i < nums.size(); ++i)
        {
            int current = 0;
            for(int j = i; j < nums.size(); ++j)
            {
                current += nums[j];
                max_sum = (current > max_sum) ? current : max_sum;
            }
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