#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> table(amount + 1, amount + 1);

        table[0] = 0;
        for(int i = 1; i <= amount; ++i)
            for(int j = 0; j < coins.size(); ++j)
                if(i - coins[j] >= 0)
                    table[i] = min(table[i], 1 + table[i - coins[j]]);

        if(table[amount] != amount + 1)
            return table[amount];
        else
            return -1;
    }
};

int main(void)
{
    int amount;
    cin >> amount;

    int data;
    vector<int> coins;
    while(cin >> data)
        coins.push_back(data);

    Solution sol;
    cout << sol.coinChange(coins, amount) << endl;

    return 0;
}