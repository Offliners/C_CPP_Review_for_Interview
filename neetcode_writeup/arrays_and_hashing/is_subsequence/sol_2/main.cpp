#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution
{
    public:
        bool isSubsequence(string s, string t)
        {
            int s_len = s.length();
            int t_len = t.length();

            if(s_len == 0)
                return true;
            
            if(t_len == 0)
                return false;
            
            if(s[s_len - 1] == t[t_len - 1])
                return isSubsequence(s.substr(0, s_len - 1), t.substr(0, t_len - 1));
            
            return isSubsequence(s, t.substr(0, t_len - 1));
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