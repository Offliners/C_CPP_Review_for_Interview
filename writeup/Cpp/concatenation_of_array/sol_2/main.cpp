#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
        vector<int> getConcatenation(vector<int>& nums)
        {
            int n = nums.size();
            for(int i = 0; i < n; ++i)
                nums.push_back(nums[i]);

            return nums;
        }
};


int main(void)
{
    int data;
    vector<int> nums;
    Solution sol;

    while(cin >> data)
        nums.push_back(data);

    vector<int> ans = sol.getConcatenation(nums);
    for(int i = 0; i < ans.size() - 1; ++i)
        cout << ans[i] << " ";

    cout << ans.back() << endl;

    return 0;
}