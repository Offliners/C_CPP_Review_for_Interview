#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int recursive_matrix_chain_order(vector<int>&, int, int);
int dp_matrix_chain_order(vector< vector<int> >&, vector< vector<int> >&, vector<int>&, int, int);
void print_matrix_order(vector< vector<int> >&, int, int);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> sequence_dim {30, 35, 15, 5, 10, 20, 25};
    cout << "Recursive approach : " << recursive_matrix_chain_order(sequence_dim, 1, sequence_dim.size() - 1) << "\n";

    int n = sequence_dim.size();
    vector< vector<int> > dp_table(n + 1, (0, (vector<int>(n + 1, 0))));
    vector< vector<int> > order_tabulation(n + 1, (0, (vector<int>(n + 1, 0))));
    cout << "Dynamic programming approach : " << dp_matrix_chain_order(order_tabulation, dp_table, sequence_dim, 1, n - 1) << "\n";

    cout << "\nMatrix Chain Order : ";
    print_matrix_order(order_tabulation, 1, n - 1);
    cout << "\n";

    return 0;
}

int recursive_matrix_chain_order(vector<int>& dim, int start, int end)
{
    if(start == end)
        return 0;
    
    int min_m = INT_MAX;
    for(int i = start; i < end; ++i)
        min_m = min(min_m, recursive_matrix_chain_order(dim, start, i)
                           + recursive_matrix_chain_order(dim, i + 1, end)
                           + dim[start - 1] * dim[i] * dim[end]);

    return min_m;
}

int dp_matrix_chain_order(vector< vector<int> > &order, vector< vector<int> > &dp, vector<int>& dim, int start, int end)
{
    if(start == end)
        return 0;

    if(dp[start][end] != 0)
        return dp[start][end];

    dp[start][end] = INT_MAX;
    for (int i = start; i < end; ++i)
    {
        int tmp = dp_matrix_chain_order(order, dp, dim, start, i)
                  + dp_matrix_chain_order(order, dp, dim, i + 1, end)
                  + dim[start - 1] * dim[i] * dim[end];
        
        if(tmp < dp[start][end])
        {
            dp[start][end] = tmp;
            order[start][end] = i;
        }
    }

    return dp[start][end];
}

void print_matrix_order(vector< vector<int> > &order, int start, int end)
{
    if(start == end)
        cout << "A" << start;
    else
    {
        cout << "(";
        print_matrix_order(order, start, order[start][end]);
        print_matrix_order(order, order[start][end] + 1, end);
        cout << ")";
    }
}