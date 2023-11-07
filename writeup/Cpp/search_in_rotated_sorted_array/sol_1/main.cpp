#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); ++i)
            if(nums[i] == target)
                return i;
        
        return -1;
    }
};


int main(void)
{
    int target;
    cin >> target;

    int data;
    vector<int> nums;
    Solution sol;

    while(cin >> data)
        nums.push_back(data);

    cout << sol.search(nums, target) << endl;

    return 0;
}