#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for(int i = 1; i < nums.size(); ++i)
        {
            int key = nums[i];
            int j = i - 1;
            while(j >= 0 && key < nums[j])
            {
                nums[j + 1] = nums[j];
                j--;
            }

            nums[j + 1] = key;
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