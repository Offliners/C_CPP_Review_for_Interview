#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int max_profit = 0;

        while(right < prices.size())
        {
            if(prices[left] < prices[right])
            {
                int profit = prices[right] - prices[left];
                max_profit = (profit > max_profit) ? profit : max_profit;
            }
            else
                left = right;
            
            ++right;
        }

        return max_profit;
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