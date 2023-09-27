#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s)
    {
        int len = 0;
        string x = s;
        x.erase(0, s.find_first_not_of(" "));
        x.erase(x.find_last_not_of(" ") + 1);
 
        for(int i = 0; i < x.length(); ++i)
        {
            if(x[i] == ' ')
                len = 0;
            else
                len++;
        }
 
        return len;
    }
};

int main(void)
{
    Solution sol;
    string s;
    getline(cin, s);

    cout << sol.lengthOfLastWord(s) << endl;

    return 0;
}