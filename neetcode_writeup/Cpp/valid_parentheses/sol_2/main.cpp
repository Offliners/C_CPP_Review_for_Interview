#include<iostream>
#include<stack>
#include<string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> check;

        for(int i = 0; i < s.length(); ++i)
        {
            if(s[i] == '(')
                check.push(')');
            else if(s[i] == '[')
                check.push(']');
            else if(s[i] == '{')
                check.push('}');
            else if(check.empty() || check.top() != s[i])
                return false;
            else
                check.pop();
        }

        return check.empty();
    }
};


int main(void)
{
    Solution sol;
    string data;

    cin >> data;

    if(sol.isValid(data))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}