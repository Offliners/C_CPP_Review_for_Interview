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
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                check.push(s[i]);
            else
            {
                if(check.empty())
                    return false;
                else
                {
                    char top = check.top();

                    if((s[i] == ')' && top != '(') || (s[i] == ']' && top != '[') || (s[i] == '}' && top != '{'))
                        return false;
                    
                    check.pop();
                }
            }
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