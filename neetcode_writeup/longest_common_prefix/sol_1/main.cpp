#include<iostream>
#include<vector>
#include<string>

#define MAX_STR_LENGTH 200

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1)
            return strs[0];

        int min_len = MAX_STR_LENGTH;
        for(int i = 0; i < strs.size(); ++i)
            if(strs[i].length() < min_len)
                min_len = strs[i].length();

        int end_index = 0;
        for(int i = 0; i <= min_len; ++i)
        {
            bool is_same = true;
            for(int j = 0; j < strs.size() - 1; ++j)
            {
                if(strs[j][i] != strs[j + 1][i])
                {
                    is_same = false;
                    break;
                }
            }

            if(!is_same)
            {
                end_index = i;
                break;
            }

            if(i == min_len)
            {
                end_index = i;
                break;
            }
        }

        string ans;
        for(int i = 0; i < end_index; ++i)
            ans.push_back(strs[0][i]);

        return ans;
    }
};

int main(void)
{
    Solution sol;
    string str;
    vector<string> strs;
    while(cin >> str)
        strs.push_back(str);

    cout << sol.longestCommonPrefix(strs) << endl;

    return 0;
}