#include<iostream>
#include<vector>

using namespace std;

int pick = 0;

int guess(int num)
{
    if(num == pick)
        return 0;
    
    return (num < pick) ? 1 : -1;
}

class Solution {
public:
    int guessNumber(int n) {
        int front = 0;
        int end = n;

        while(front <= end)
        {
            int mid = front + (end - front) / 2;
            if(guess(mid) == 0)
                return mid;
            else if(guess(mid) == -1)
                end = mid - 1;
            else
                front = mid + 1;
        }

        return -1;
    }
};


int main(void)
{
    int n;
    cin >> n >> pick;

    Solution sol;
    cout << sol.guessNumber(n) << endl;
    
    return 0;
}