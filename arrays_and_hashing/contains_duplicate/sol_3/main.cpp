#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution
{
    public:
        bool containsDuplicate(vector<int>& nums)
        {
            unordered_map<int, int> umap;
            
            for(int i = 0; i < nums.size(); ++i)
            {
                umap[nums[i]]++;

                if(umap[nums[i]] > 1)
                    return true;
            }

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