#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string new_s;
        for(int i = 0; i < s.length(); ++i)
            if((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57))
                new_s += tolower(s[i]);

        string rev_s;
        for(int i = new_s.length() - 1; i >= 0; --i)
            if((new_s[i] >= 65 && new_s[i] <= 90) || (new_s[i] >= 97 && new_s[i] <= 122) || (new_s[i] >= 48 && new_s[i] <= 57))
                rev_s += new_s[i];

        return (rev_s == new_s);
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