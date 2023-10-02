#include<iostream>
#include<vector>

#define MAXSIZE 46

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> table(MAXSIZE, 1);

        if(n == 0 || n == 1)
            return table[n];

        for(int i = 2; i <= n; ++i)
            table[i] = table[i - 1] + table[i - 2];

        return table[n];
    }
};

int main(void)
{
    Solution sol;
    int n;

    cin >> n;

    cout << sol.climbStairs(n) << endl;

    return 0;
}