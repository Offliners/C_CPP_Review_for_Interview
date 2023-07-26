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

            return (unique(nums.begin(), nums.end()) != nums.end());
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