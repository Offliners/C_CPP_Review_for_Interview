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
    Solution sol;
    int target, data;
    vector<int> nums;
   
    cin >> target;
    while(cin >> data)
        nums.push_back(data);

    int ans =sol.search(nums, target);
    cout << ans << endl;

    return 0;
}