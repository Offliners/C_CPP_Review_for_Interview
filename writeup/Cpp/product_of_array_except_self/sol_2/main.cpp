#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);
        ans[0] = 1;
        for(int i = 1; i < n; ++i)
            ans[i] = ans[i - 1] * nums[i - 1];

        int right = 1;
        for(int i = n - 1; i >= 0; --i)
        {
            ans[i] *= right;
            right *= nums[i];
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