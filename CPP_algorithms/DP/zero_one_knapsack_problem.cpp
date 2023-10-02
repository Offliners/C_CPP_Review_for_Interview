#include<iostream>
#include<vector>

using namespace std;

int recursive_zn_kp(vector<int>&, vector<int>&, int, int);
int dp_zn_kp(vector< vector<int> >&, vector<int>&, vector<int>&, int, int);
void find_solution(vector< vector<int> >&, vector<int>&, vector<int>&, int, int);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> weights{10, 20, 30};
    vector<int> values{60, 100, 120};

    int n = weights.size();
    int w = 50;

    cout << "Recursive approach : " << recursive_zn_kp(weights, values, n, w) << "\n";

    vector< vector<int> > dp_table(n + 1, (0, vector<int>(w + 1, 0)));
    cout << "Dynamic programming approach : " << dp_zn_kp(dp_table, weights, values, n, w) << "\n";

    cout << "\nPick method :\n";
    find_solution(dp_table, weights, values, n, w);
    
    return 0;
}

int recursive_zn_kp(vector<int>& weights, vector<int> &values, int n, int w)
{
    if(n == 0 || w == 0)
        return 0;
    
    if(weights[n - 1] > w)
        return recursive_zn_kp(weights, values, n, w);
    else
        return max(values[n - 1] + recursive_zn_kp(weights, values, n - 1, w - weights[n- 1]), recursive_zn_kp(weights, values, n - 1, w));
}

int dp_zn_kp(vector< vector<int> > &dp, vector<int> &weights, vector<int> &values, int n, int w)
{
    for(int i = 0; i < n + 1; ++i)
    {
        for(int j = 0; j < w + 1; ++j)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(weights[i - 1] <= j)
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][w];
}

void find_solution(vector< vector<int> > &dp, vector<int> &weights, vector<int> &values, int n, int w)
{
    for(int i = n - 1; i > 0; --i)
    {
        if(dp[i][w] > dp[i - 1][w])
        {
            w -= weights[i];
            cout << "Pick item " << i << "(value = " << values[i] << ")\n";
        }
    }
    cout << "\n";
}