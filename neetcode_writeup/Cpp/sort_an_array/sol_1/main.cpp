#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = i; j < nums.size(); ++j)
            {
                if(nums[j] < nums[i])
                {
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
        }

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
    
    vector<int> ans = sol.sortArray(nums);
    for(int i = 0; i < ans.size() - 1; ++i)
        cout << ans[i] << " ";

    cout << ans.back() << endl;

    return 0;
}