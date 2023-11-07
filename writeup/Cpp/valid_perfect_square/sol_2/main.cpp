#include<iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int front = 0;
        int end = num;

        while(front <= end)
        {
            long long int mid = front + (end - front) / 2;
            if(mid * mid == num)
                return true;
            else if(mid * mid < num)
                front = mid + 1;
            else
                end = mid - 1;
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