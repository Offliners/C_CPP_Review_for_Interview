#include<iostream>
#include<cmath>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        return -0.5 + sqrt(0.25 + 2 * (long)n);
    }
};

int main(void)
{
    int n;
    cin >> n;

    Solution sol;
    cout << sol.arrangeCoins(n) << endl;

    return 0;
}