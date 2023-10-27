#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();

        while(left < right)
        {
            int mid = (left + right) / 2;
            if(target > nums[mid])
                left = mid + 1;
            else
                right = mid;
        }

        return left;
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