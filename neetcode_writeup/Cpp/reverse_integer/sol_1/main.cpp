#include<iostream>
#include<climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long int reverse = 0;
        while(x)
        {
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }

        return (reverse > INT_MAX || reverse < INT_MIN) ? 0 : reverse;
    }
};

int main(void)
{
    int n;
    cin >> n;

    Solution sol;
    cout << sol.reverse(n) << endl;

    return 0;
}