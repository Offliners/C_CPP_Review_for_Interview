#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())
            return {-1, -1}; 

        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i)
            if(nums[i] == target)
                ans.push_back(i);

        if(ans.empty())
            return {-1, -1};

        return {ans.front(), ans.back()};
    }
};

int main(void)
{
    Solution sol;
    int target, data;
    vector<int> nums;
   
    cin >> target;
    while(cin >> data)
        nums.push_back(data);

    vector<int> ans =sol.searchRange(nums, target);
    cout << ans.front() << " " << ans.back() << endl;

    return 0;
}