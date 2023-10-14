#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int end = nums.size();
        for(int i = 1; i < end; ++i)
        {
            if(nums[i - 1] == nums[i])
            {
                for(int j = i; j < end; ++j)
                    nums[j - 1] = nums[j];

                --i;
                --end;
            }
        }

        return end;
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