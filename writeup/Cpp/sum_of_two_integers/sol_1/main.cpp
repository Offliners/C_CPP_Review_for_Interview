#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        return a + b;
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