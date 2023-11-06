#include<iostream>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int count = 0;
        for(int i = 1; i <= n; ++i)
        {
            n -= i;
            if(n < 0)
                break;

            ++count;
        }

        return count;
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