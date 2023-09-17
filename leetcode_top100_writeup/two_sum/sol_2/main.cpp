#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        vector<int> ans;

        for(int i = 0; i < nums.size(); ++i)
        {
            if(umap.count(nums[i]))
            {
                ans.push_back(umap[nums[i]]);
                ans.push_back(i);
                break;
            }

            umap[target - nums[i]] = i;
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