#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> table(nums.begin(), nums.end());
        vector<int> ans(nums.size() - table.size());
        
        int j = 0;
        for(int i = 1; i <= nums.size(); ++i)
        {
            if(table.count(i) == 0)
            {
                ans[j] = i;
                ++j;
            }
        }

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