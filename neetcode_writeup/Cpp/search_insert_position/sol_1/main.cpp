#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); ++i)
            if(nums[i] >= target)
                return i;

        return nums.size();
    }
};

int main(void)
{
    int target, data;
    vector<int> nums;
    Solution sol;

    cin >> target;
    while(cin >> data)
        nums.push_back(data);
    
    int ans = sol.searchInsert(nums, target);
    cout << ans << endl;

    return 0;
}