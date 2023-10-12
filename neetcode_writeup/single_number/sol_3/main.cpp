#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) { 
        int n = nums[0];
        for(int i = 1; i < nums.size(); ++i)
            n ^= nums[i];

        return n;
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