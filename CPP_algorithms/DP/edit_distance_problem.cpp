#include<iostream>
#include<string>
#include<vector>

using namespace std;

int recursive_edit_distance(string, string, int, int);
int dp_edit_distance(vector< vector<int> >&, string, string, int, int);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str1 = "banana";
    string str2 = "aeniqadikjaz";

    int n = str1.length();
    int m = str2.length();

    cout << "Recursive approach : " << recursive_edit_distance(str1, str2, n, m) << "\n";

    vector< vector<int> > dp_table(n + 1, (0, (vector<int>(m + 1, 0))));
    cout << "Dynamic programming approach : " << dp_edit_distance(dp_table, str1, str2, n, m) << "\n";

    return 0;
}

int recursive_edit_distance(string str1, string str2, int n, int m)
{
    if(n == 0)
        return m;
    
    if(m == 0)
        return n;

    if(str1[n - 1] == str2[m - 1])
        return recursive_edit_distance(str1, str2, n - 1, m - 1);
    else
        return 1 + min(recursive_edit_distance(str1, str2, n - 1, m), min(recursive_edit_distance(str1, str2, n, m - 1), recursive_edit_distance(str1, str2, n - 1, m - 1)));
}

int dp_edit_distance(vector< vector<int> > &dp, string str1, string str2, int n, int m)
{
    for(int i = 0; i < n + 1; ++i)
    {
        for(int j = 0; j < m + 1; ++j)
        {
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else if(str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
        }
    }

    return dp[n][m];
}