#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;

        for(int i = 0; i < strs[0].size(); ++i)
        {
            for(int j = 0; j < strs.size(); ++j)
                if(i == strs[j].length() || strs[j][i] != strs[0][i])
                    return ans;

            ans.push_back(strs[0][i]);
        }

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