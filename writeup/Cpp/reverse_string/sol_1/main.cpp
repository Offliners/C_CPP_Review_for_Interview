#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0; i < s.size() / 2; ++i)
            swap(s[i], s[s.size() - i - 1]);
    }
};

int main(void)
{
    char chr;
    vector<char> s;

    while(cin >> chr)
        s.push_back(chr);

    Solution sol;
    sol.reverseString(s);

    for(int i = 0; i < s.size() - 1; ++i)
        cout << s[i] << " ";
    cout << s.back() << endl;

    return 0;
}