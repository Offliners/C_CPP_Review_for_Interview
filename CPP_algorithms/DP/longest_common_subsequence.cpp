#include<iostream>
#include<string>
#include<vector>

using namespace std;

int recursive_LCS(string, string, int, int);
int dp_LCS(vector< vector<int> >&, string, string, int, int);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str1 = "banana";
    string str2 = "aeniqadikjaz";

    int n = str1.length();
    int m = str2.length();

    cout << "Recursive approach : " << recursive_LCS(str1, str2, n, m) << "\n";

    vector< vector<int> > dp_table(n + 1, (-1, (vector<int>(m + 1, -1))));
    cout << "Dynamic programming approach : " << dp_LCS(dp_table, str1, str2, n, m) << "\n";

    return 0;
}

int recursive_LCS(string str1, string str2, int n, int m)
{
    if(n == 0 || m == 0)
        return 0;
    
    if(str1[n - 1] == str2[m - 1])
        return 1 + recursive_LCS(str1, str2, n - 1, m - 1);
    else
        return max(recursive_LCS(str1, str2, n - 1, m), recursive_LCS(str1, str2, n, m - 1));
}

int dp_LCS(vector< vector<int> > &dp, string str1, string str2, int n, int m)
{
    if(n == 0 || m == 0)
        return 0;
    
    if(str1[n - 1] == str2[m - 1])
    {
        dp[n][m] = 1 + dp_LCS(dp, str1, str2, n - 1, m - 1);
        return dp[n][m];
    }
    
    if(dp[n][m] != -1)
        return dp[n][m];
    
    dp[n][m] = max(dp_LCS(dp, str1, str2, n - 1, m), dp_LCS(dp, str1, str2, n, m - 1));

    return dp[n][m];
}