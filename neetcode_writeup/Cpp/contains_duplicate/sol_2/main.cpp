#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
    public:
        bool containsDuplicate(vector<int>& nums)
        {
            sort(nums.begin(), nums.end());
            for(int i = 0; i < nums.size() - 1; ++i)
                if(nums[i] == nums[i + 1])
                    return true;
            
            return false;
        }
};


int main(void)
{
    int data;
    vector<int> nums;
    Solution sol;

    while(cin >> data)
        nums.push_back(data);
    
    if(sol.containsDuplicate(nums))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}