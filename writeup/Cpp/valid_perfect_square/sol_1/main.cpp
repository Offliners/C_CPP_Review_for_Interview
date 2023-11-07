#include<iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1)
            return true;

        for(long long int i = 2; i <= num / 2; ++i)
        {
            long long int temp = i * i;
            if(temp == num)
                return true;
        }

        return false;
    }
};

int main(void)
{
    int n;
    cin >> n;

    Solution sol;
    if(sol.isPerfectSquare(n))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}