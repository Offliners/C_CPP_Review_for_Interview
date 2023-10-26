#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x != 0 && x % 10 == 0))
            return false;
        
        long long int reverse = 0;
        while(x > reverse)
        {
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }

        return (reverse == x) || (x == reverse / 10);
    }
};

int main(void)
{
    int n;
    cin >> n;

    Solution sol;
    if(sol.isPalindrome(n))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}