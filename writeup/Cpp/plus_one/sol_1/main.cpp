#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans(digits.size() + 1, 0);

        int carry = 1;
        for(int i = digits.size() - 1; i >= 0; --i)
        {
            int add_sum = digits[i] + carry;
            carry = add_sum / 10;
            ans[i + 1]  = add_sum % 10;
        }

        if(carry)
            ans[0] = carry;
        else
            ans.erase(ans.begin());

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
    vector<int> ans = sol.plusOne(nums);

    for(int i = 0; i < ans.size() - 1; ++i)
        cout << ans[i] << " ";

    cout << ans.back() << endl;

    return 0;
}