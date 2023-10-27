#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        s = ' ' + s;

        for(int i = s.length() - 1; i >= 0; --i)
        {
            if(s[i] != ' ')
                count++;

            if(s[i] != ' ' && s[i - 1] == ' ')
                break;
        }

        return count;
    }
};

int main(void)
{
    Solution sol;
    string s;
    getline(cin, s);

    cout << sol.lengthOfLastWord(s) << endl;

    return 0;
}