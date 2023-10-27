#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);

        for(int i = 0; i < n; ++i)
            temp[(i + k) % n] = nums[i];
        
        nums = temp;
    }
};

int main(void)
{
    int k, data;
    cin >> k;

    vector<int> nums;
    while(cin >> data)
        nums.push_back(data);
    
    Solution sol;
    sol.rotate(nums, k);

    for(int i = 0; i < nums.size() - 1; ++i)    
        cout << nums[i] << " ";
    cout << nums.back() << endl;

    return 0;
}