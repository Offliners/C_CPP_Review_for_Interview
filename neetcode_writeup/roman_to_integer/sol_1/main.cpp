#include<iostream>
#include<string>
#include<map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> table = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int ans = 0;
        for(int i = 0; i < s.length(); ++i)
        {
            if(i + 1 < s.length() && (table[s[i]] < table[s[i + 1]]))
                ans -= table[s[i]];
            else
                ans += table[s[i]];
        }

        return ans;
    }
};

int main(void)
{
    string s;
    cin >> s;

    Solution sol;
    cout << sol.romanToInt(s) << endl;

    return 0;
}