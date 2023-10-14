#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; ++i)
        {
            int min_index = i;
            for(int j = i + 1; j < nums.size(); ++j)
                if(nums[min_index] > nums[j])
                    min_index = j;
            
            int temp = nums[min_index];
            nums[min_index] = nums[i];
            nums[i] = temp;
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