#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(target == nums[mid])
                return mid;
            else if(target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }

        return -1; 
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

    cout << sol.search(nums, target) << endl;

    return 0;
}