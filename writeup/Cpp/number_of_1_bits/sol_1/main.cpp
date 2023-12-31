#include<iostream>
#include<bitset>
#include<string>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        while(n)
        {
            n &= n - 1;
            ++count;
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