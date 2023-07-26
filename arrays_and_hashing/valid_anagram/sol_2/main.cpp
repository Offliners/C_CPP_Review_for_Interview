#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution
{
    public:
        bool isAnagram(string s, string t)
        {
            if(s.length() != t.length())
                return false;

            sort(s.begin(), s.end());
            sort(t.begin(), t.end());

            if(s != t)
                return false;
            
            return true;
        }
};


int main(void)
{
    string s, t;
    Solution sol;

    cin >> s;
    cin >> t;
    
    if(sol.isAnagram(s, t))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}