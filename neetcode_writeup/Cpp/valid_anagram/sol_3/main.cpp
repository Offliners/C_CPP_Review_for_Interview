#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution
{
    public:
        bool isAnagram(string s, string t)
        {
            if(s.length() != t.length())
                return false;

            unordered_map<char, int> smap;
            unordered_map<char, int> tmap;
            for(int i = 0; i < s.length(); ++i)
            {
                smap[s[i]]++;
                tmap[t[i]]++;
            }
            
            for(int i = 0; i < smap.size(); ++i)
                if(smap[i] != tmap[i])
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