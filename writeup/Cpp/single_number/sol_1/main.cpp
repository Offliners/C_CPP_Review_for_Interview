#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 1; i += 2)
            if(nums[i] != nums[i + 1])
                return nums[i];

        return nums[nums.size() - 1];
    }
};


int main(void)
{
    int data;
    vector<int> nums;
    Solution sol;

    while(cin >> data)
        nums.push_back(data);
    
    cout << sol.singleNumber(nums) << endl;

    return 0;
}