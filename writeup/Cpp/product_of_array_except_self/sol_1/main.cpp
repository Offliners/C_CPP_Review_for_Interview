#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());

        for(int i = 0; i < nums.size(); ++i)
        {
            int product = 1;
            for(int j = 0; j < nums.size(); ++j)
                if(i != j)
                    product *= nums[j];

            ans[i] = product;
        }

        return ans;
    }
};

int main(void)
{
    int data;
    vector<int> nums;
    while(cin >> data)
        nums.push_back(data);
    
    Solution sol;
    vector<int> ans = sol.productExceptSelf(nums);

    for(int i = 0; i < ans.size() - 1; ++i)
        cout << ans[i] << " ";
    cout << ans.back() << endl;

    return 0;
}