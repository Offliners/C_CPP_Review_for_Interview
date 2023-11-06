#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; ++i)
            if(nums[i] > nums[i + 1])
                return nums[i + 1];
        
        return nums.front();
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