#include<iostream>
#include<bitset>
#include<string>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int rev = 0;
        for(int i = 0; i < 32; ++i)
        {
            int bit = (n >> i) & 1;
            rev |= bit << (31 - i);
        }

        return rev;
    }
};

int main(void)
{
    string n;
    cin >> n;

    Solution sol;
    cout << sol.reverseBits(bitset<32>(n).to_ulong()) << endl;

    return 0;
}