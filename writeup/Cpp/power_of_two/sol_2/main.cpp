#include<iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && ((n & n - 1) == 0);
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