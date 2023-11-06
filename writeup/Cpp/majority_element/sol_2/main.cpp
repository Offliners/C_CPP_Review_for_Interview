#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> table;

        for(int i = 0; i < nums.size(); ++i)
            table[nums[i]]++;

        int half_size = nums.size() / 2;
        for(auto n : table)
            if(n.second > half_size)
                return n.first;

        return -1;
    }
};

int main(void)
{
    int data;
    vector<int> nums;
    while(cin >> data)
        nums.push_back(data);

    Solution sol;
    cout << sol.majorityElement(nums) << endl;

    return 0;
}