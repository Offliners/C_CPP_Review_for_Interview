#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
        bool containsDuplicate(vector<int>& nums)
        {
            for(int i = 0; i < nums.size(); ++i)
                for(int j = i + 1; j < nums.size(); ++j)
                    if(nums[i] == nums[j])
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