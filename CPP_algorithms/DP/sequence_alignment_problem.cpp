#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int dp_sequence_alignment_problem(vector< vector<int> >&, string, string, int, int, int);
void find_solution(vector< vector<int> >&, string, string, int, int, int);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str1 = "banana";
    string str2 = "aeniqadikjaz";

    int cost_substitute = 7;
    int cost_insert = 4;
    int cost_delete = 4;
    int n = str1.length();
    int m = str2.length();
    vector< vector<int> > dp_table(n + 1, (0, vector<int>(m + 1, 0)));

    cout << "Minimum cost : " << dp_sequence_alignment_problem(dp_table, str1, str2, cost_substitute, cost_insert, cost_delete) << "\n";

    cout << "\nAlignment result :\n";
    find_solution(dp_table, str1, str2, cost_substitute, cost_insert, cost_delete);

    return 0;
}

int dp_sequence_alignment_problem(vector< vector<int> > &dp, string str1, string str2, int cost_substitute, int cost_insert, int cost_delete)
{
    int n = str1.length();
    int m = str2.length();

    for(int i = 1; i < n + 1; ++i)
        dp[i][0] = i * cost_delete;

    for(int j = 1; j < m + 1; ++j)
        dp[0][j] = j * cost_insert;

    for(int i = 1; i < n + 1; ++i)
    {
        for(int j = 1; j < m + 1; ++j)
        {
            if(str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j - 1] + cost_substitute, min(dp[i - 1][j] + cost_delete, dp[i][j - 1] + cost_insert));
        }
    }

    return dp[n][m];
}

void find_solution(vector< vector<int> > &dp, string str1, string str2, int cost_substitute, int cost_insert, int cost_delete)
{
    int n = str1.length();
    int m = str2.length();
    int max_len = n + m;

    string str1_align(max_len + 1, ' ');
    string str2_align(max_len + 1, ' ');

    int row = n;
    int col = m;
    int str1_pos = max_len;
    int str2_pos = max_len;
    while(row > 0 && col > 0)
    {
        if((str1[row - 1] == str2[col - 1]) || (dp[row - 1][col - 1] == dp[row][col] - cost_substitute))
        {
            str1_align[str1_pos] = str1[row - 1];
            str2_align[str2_pos] = str2[col - 1];
            --str1_pos;
            --str2_pos;
            --row;
            --col;
        }
        else if(dp[row - 1][col] == dp[row][col] - cost_delete)
        {
            str1_align[str1_pos] = str1[row - 1];
            str2_align[str2_pos] = '_';
            --str1_pos;
            --str2_pos;
            --row;
        }
        else if(dp[row][col - 1] == dp[row][col] - cost_insert)
        {
            str1_align[str1_pos] = '_';
            str2_align[str2_pos] = str2[col - 1];
            --str1_pos;
            --str2_pos;
            --col;
        }
    }

    while(str1_pos > 0)
    {
        if(row > 0)
        {
            --row;
            str1_align[str1_pos] = str1[row];
        }

        --str1_pos;      
    }

    while(str2_pos > 0)
    {
        if(col > 0)
        {
            --col;
            str2_align[str2_pos] = str2[col];
        }

        --str2_pos;
    }

    for(int i = 0; i < max_len + 1; ++i)
    {
        if(str1_align[i] == ' ' && str2_align[i] == ' ')
            continue;

        if(str1_align[i] == ' ' && str2_align[i] != ' ')
            str1_align[i] = '_';
        else if(str1_align[i] != ' ' && str2_align[i] == ' ')
            str2_align[i] = '_';
    }

    str1_align.erase(remove(str1_align.begin(), str1_align.end(), ' '), str1_align.end());
    str2_align.erase(remove(str2_align.begin(), str2_align.end(), ' '), str2_align.end());

    cout << str1_align << "\n";
    cout << str2_align << "\n";
}