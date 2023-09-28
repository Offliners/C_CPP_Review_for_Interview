#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != val)
            {
                nums[k] = nums[i];
                ++k;
            }
        }
        
        return k;
    }
};

int main(void)
{
    int val, data;
    vector<int> nums;
    Solution sol;

    cin >> val;
    while(cin >> data)
        nums.push_back(data);
    
    int k = sol.removeElement(nums, val);
    cout << k << endl;
    for(int i = 0; i < k - 1; ++i)
        cout << nums[i] << " ";

    cout << nums[k - 1] << endl;

    return 0;
}