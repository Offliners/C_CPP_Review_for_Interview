#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = 0; j < nums.size(); ++j)
            {
                if(i == j)
                    continue;

                if(nums[i] + nums[j] == target)
                {
                    if(i < j)
                    {
                        ans.push_back(i);
                        ans.push_back(j);
                    }
                    else
                    {
                        ans.push_back(j);
                        ans.push_back(i);
                    }

                    return ans;
                }
            }
        }

        return ans;
    }
};


int main(void)
{
    int data;
    vector<int> nums;
    Solution sol;

    while(cin >> data)
        nums.push_back(data);
    
    int target = nums.back();
    nums.pop_back();
    
    vector<int> ans = sol.twoSum(nums, target);
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << endl;

    return 0;
}