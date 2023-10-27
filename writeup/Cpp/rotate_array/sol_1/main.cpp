#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        for(int i = 0; i < k; ++i)
        {
            int end = nums.back();
            for(int j = nums.size() - 1; j > 0; --j)
                nums[j] = nums[j - 1];
            
            nums[0] = end;
        }
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