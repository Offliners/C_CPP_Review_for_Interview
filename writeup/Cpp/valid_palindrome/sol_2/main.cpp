#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while(left <= right)
        {
            if(!isAlpha(s[left]))
            {
                ++left;
                continue;
            }

            if(!isAlpha(s[right]))
            {
                --right;
                continue;
            }

            if(tolower(s[left]) != tolower(s[right]))
                return false;
            else
            {
                ++left;
                --right;
            }
        }

        return true;
    }

    bool isAlpha(char c)
    {
        if((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
            return true;
        else
            return false;
    }
};


int main(void)
{
    string s;
    getline(cin, s);

    Solution sol;
    if(sol.isPalindrome(s))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}