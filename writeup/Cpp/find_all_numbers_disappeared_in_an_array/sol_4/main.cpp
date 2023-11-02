#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i)
        {
            int index = abs(nums[i]) - 1;
            nums[index] = -1 * abs(nums[index]);
        }

        vector<int> ans; 
        for(int i = 0; i < nums.size(); ++i)
            if(nums[i] > 0)
                ans.push_back(i + 1);

        return ans;
    }
};

int main(void)
{
    Solution sol;
    int data;
    vector<int> nums;

    while(cin >> data)
        nums.push_back(data);

    vector<int> ans = sol.findDisappearedNumbers(nums);

    if(ans.size() != 0)
    {
        for(int i = 0; i < ans.size() - 1; ++i)
            cout << ans[i] << " ";

        cout << ans.back() << endl;
    }
    
    return 0;
}