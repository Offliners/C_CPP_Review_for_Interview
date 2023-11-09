#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0)
        {
            int temp = (a & b) << 1;
            a = a ^ b;
            b = temp;
        }

        return a;
    }
};


int main(void)
{
    int a, b;
    cin >> a >> b;

    Solution sol;
    cout << sol.getSum(a, b) << endl;

    return 0;
}