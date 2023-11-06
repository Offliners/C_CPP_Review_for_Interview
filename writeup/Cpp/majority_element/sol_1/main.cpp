#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        return nums[nums.size() / 2];
    }
};

int main(void)
{
    int data;
    vector<int> nums;
    while(cin >> data)
        nums.push_back(data);

    Solution sol;
    cout << sol.majorityElement(nums) << endl;

    return 0;
}