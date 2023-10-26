#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign = 1;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] < 0)
                sign *= -1;
            else if(nums[i] == 0)
                return 0;
        }
        
        if(sign > 0)
            return 1;
        else
            return -1;
    }
};


int main(void)
{
    int data;
    vector<int> nums;
    Solution sol;

    while(cin >> data)
        nums.push_back(data);
    
    cout << sol.arraySign(nums) << endl;

    return 0;
}