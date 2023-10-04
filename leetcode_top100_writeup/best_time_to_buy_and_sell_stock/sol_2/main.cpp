#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest = prices.front();
        int max_profile = 0;

        for(int i = 1; i < prices.size(); ++i)
        {
            if(prices[i] < lowest)
                lowest = prices[i];

            max_profile = (prices[i] - lowest > max_profile) ? prices[i] - lowest : max_profile;
        }
        
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

    cout << sol.maxProfit(nums) << endl;

    return 0;
}