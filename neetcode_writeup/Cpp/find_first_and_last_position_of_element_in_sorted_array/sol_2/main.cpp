#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        int start = binary_search(nums, left, right, target);
        int end = binary_search(nums, left, right, target + 1) - 1;

        if(start < nums.size() && nums[start] == target)
            return {start, end};

        return {-1, -1};
    }

    int binary_search(vector<int>& nums, int left, int right, int target) {
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(target <= nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }

        return left;
    }
};

int main(void)
{
    Solution sol;
    int target, data;
    vector<int> nums;
   
    cin >> target;
    while(cin >> data)
        nums.push_back(data);

    vector<int> ans =sol.searchRange(nums, target);
    cout << ans.front() << " " << ans.back() << endl;

    return 0;
}