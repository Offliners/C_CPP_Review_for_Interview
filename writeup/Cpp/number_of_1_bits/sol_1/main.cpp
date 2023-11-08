#include<iostream>
#include<bitset>
#include<string>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        while(n != 0)
        {
            if(n & 1 == 1)
                ++count;
            
            n = n >> 1;
        }

        return count;
    }
};

int main(void)
{
    string n;
    cin >> n;

    Solution sol;
    cout << sol.hammingWeight(bitset<32>(n).to_ulong()) << endl;

    return 0;
}