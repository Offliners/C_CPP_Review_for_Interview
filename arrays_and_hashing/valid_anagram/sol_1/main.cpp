#include<iostream>
#include<string>
#include<vector>

#define NUM_ENGLISH_LETTER 26

using namespace std;

class Solution
{
    public:
        bool isAnagram(string s, string t)
        {
            if(s.length() != t.length())
                return false;

            vector<int> s_arr(NUM_ENGLISH_LETTER, 0);
            vector<int> t_arr(NUM_ENGLISH_LETTER, 0);

            for(int i = 0; i < s.length(); ++i)
            {
                s_arr[s[i] - 'a']++;
                t_arr[t[i] - 'a']++;
            }

            for(int i = 0; i < NUM_ENGLISH_LETTER; ++i)
                if(s_arr[i] != t_arr[i])
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