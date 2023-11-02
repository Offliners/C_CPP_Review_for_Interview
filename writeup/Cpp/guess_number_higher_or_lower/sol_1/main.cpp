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
        for(int i = 1; i <=n; ++i)
            if(!guess(i))
                return i;
        
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