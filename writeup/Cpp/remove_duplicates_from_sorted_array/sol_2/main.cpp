#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] != nums[i - 1])
            {
                nums[j] = nums[i];
                ++j;
            }
        }

        return j;
    }
};

int main(void)
{
    int val, data;
    vector<int> nums;
    Solution sol;

    while(cin >> data)
        nums.push_back(data);
    
    int k = sol.removeDuplicates(nums);

    cout << k << endl;
    
    for(int i = 0; i < k - 1; ++i)
        cout << nums[i] << " ";
    
    cout << nums.back() << endl;

    return 0;
}