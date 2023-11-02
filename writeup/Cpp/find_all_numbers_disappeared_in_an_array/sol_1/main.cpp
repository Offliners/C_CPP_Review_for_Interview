#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;

        for(int i = 1; i <= nums.size(); ++i)
        {
            int flag = false;
            for(int j = 0; j < nums.size(); ++j)
            {
                if(nums[j] == i)
                {
                    flag = true;
                    break;
                }
            }

            if(!flag)
                ans.push_back(i);
        }

        return  ans;
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