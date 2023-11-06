#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int front = 0;
        int end = nums.size() - 1;

        while(front + 1 < end)
        {
            int mid = front + (end - front) / 2;
            if((nums[front] > nums[end]) && (nums[mid] > nums[end]))
                front = mid;
            else
                end = mid;
        }

        return min(nums[front], nums[end]);
    }
};


int main(void)
{
    int data;
    vector<int> nums;
    Solution sol;

    while(cin >> data)
        nums.push_back(data);

    cout << sol.findMin(nums) << endl;

    return 0;
}