#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution
{
    public:
        bool isSubsequence(string s, string t)
        {
            int i = 0, j = 0;
            while (i < s.length() && j < t.length()) 
            {
                if(s[i] == t[j])
                    ++i;
                j++;
            }

            return i == s.length();
        }
};

int main(void)
{
    Solution sol;
    string s, t;
    cin >> s >> t;
    
    if(sol.isSubsequence(s, t))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}