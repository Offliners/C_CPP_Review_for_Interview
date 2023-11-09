#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = n * (n + 1) / 2;

        for(int i = 0; i < n; ++i)
            total -= nums[i];
        
        return total;
    }
};

int main(void)
{
    Solution sol;
    int data;
    vector<int> nums;

    while(cin >> data)
        nums.push_back(data);

    cout << sol.missingNumber(nums) << endl;

    return 0;
}