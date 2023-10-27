#include<iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int res = 0;
        while(n > 0)
        {
            res += n % 2;
            n /= 2;
        }

        return (res == 1);
    }
};

int main(void)
{
    int n;
    cin >> n;
    
    Solution sol;
    if(sol.isPowerOfTwo(n))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}