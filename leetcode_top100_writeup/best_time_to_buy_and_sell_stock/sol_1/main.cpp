#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profile = 0;
        for(int i = 0; i < prices.size(); ++i)
            for(int j = i + 1; j < prices.size(); ++j)
                if(prices[j] - prices[i] > max_profile)
                    max_profile = prices[j] - prices[i];
 
        return max_profile;
    }
};

int main(void)
{
    Solution sol;
    int data;
    vector<int> nums;

    while(cin >> data)
        nums.push_back(data);

    cout << sol.search(nums) << endl;

    return 0;
}