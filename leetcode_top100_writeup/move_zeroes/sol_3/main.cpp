#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;

        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != 0 && nums[slow] == 0)
            {
                int temp = nums[i];
                nums[i] = nums[slow];
                nums[slow] = temp;
            }

            if(nums[slow] != 0)
                ++slow;
        }
    }
};

int main(void)
{
    Solution sol;
    int data;
    vector<int> nums;

    while(cin >> data)
        nums.push_back(data);

    sol.moveZeroes(nums);
    for(int i = 0; i < nums.size() - 1; ++i)
        cout << nums[i] << " ";
    cout << nums.back() << endl;

    return 0;
}