#include<iostream>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int front = 0;
        int end = n;

        while(front <= end)
        {
            long mid = front + (end - front) / 2;
            long target = mid * (mid + 1) / 2;
            if(target == n)
                return mid;
            else if(target < n)
                front = mid + 1;
            else
                end = mid - 1;
        }

        return end;
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