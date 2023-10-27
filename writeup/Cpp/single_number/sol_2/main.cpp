#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) { 
        unordered_map<int, int> table;
        for(auto num : nums)
		    table[num]++;

        for(auto data : table)
		    if(data.second == 1)
		        return data.first;
               
	   return -1;
    }
};


int main(void)
{
    int data;
    vector<int> nums;
    Solution sol;

    while(cin >> data)
        nums.push_back(data);
    
    cout << sol.singleNumber(nums) << endl;

    return 0;
}