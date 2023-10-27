#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
    
        int table[10];
        int count = 0;
        for(int i = 0; x != 0; ++i)
        {
            table[i] = x % 10;
            x /= 10;
            ++count;
        }

        int len = (count % 2 == 0) ? count / 2 : count / 2 + 1;

        for(int i = 0; i < len; ++i)
            if(table[i] != table[count - i - 1])
                return false;

        return true;
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