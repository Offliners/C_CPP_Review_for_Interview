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

            vector<int> subsequence_index;
            int count = 0;
            for(int i = 0; i < s_len; ++i)
            {
                for(int j = count; j < t_len; ++j)
                {
                    if(s[i] == t[j])
                    {
                        subsequence_index.push_back(j);
                        count = j + 1;
                        break;
                    }
                }
            }

            if(subsequence_index.size() != s_len)
                return false;

            for(int i = 0; i < subsequence_index.size() - 1; ++i)
                if(subsequence_index[i] >= subsequence_index[i + 1])
                    return false;
            
            return true;
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