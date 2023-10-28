#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> right_table(n);
        right_table[n - 1] = 1;
        for(int i = n - 2; i >= 0; --i)
            right_table[i] = right_table[i + 1] * nums[i + 1];

        vector<int> left_table(n);
        left_table[0] = 1;
        for(int i = 1; i < n; ++i)
            left_table[i] = left_table[i - 1] * nums[i - 1];

        vector<int> ans(n);
        for(int i = 0; i < n; ++i)
            ans[i] = left_table[i] * right_table[i];
        
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