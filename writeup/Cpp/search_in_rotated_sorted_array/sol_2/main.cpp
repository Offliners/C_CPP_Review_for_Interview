#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int front = 0;
        int end = nums.size() - 1;

        while(front <= end)
        {
            int mid = front + (end - front) / 2;
            if(nums[mid] == target)
                return mid;

            if(nums[front] <= nums[mid])
            {
                if(nums[front] <= target && target <= nums[mid])
                    end = mid - 1;
                else
                    front = mid + 1;
            }
            else
            {
                if(nums[mid] <= target && target <= nums[end])
                    front = mid + 1;
                else
                    end = mid - 1;
            }
        }

        return -1;
    }
};


int main(void)
{
    int target;
    cin >> target;

    int data;
    vector<int> nums;
    Solution sol;

    while(cin >> data)
        nums.push_back(data);

    cout << sol.search(nums, target) << endl;

    return 0;
}