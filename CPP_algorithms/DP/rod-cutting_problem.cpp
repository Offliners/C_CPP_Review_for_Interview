#include<iostream>
#include<vector>

using namespace std;

int recursive_cut_rod(vector<int>&, int);
int dp_cut_rod(vector<int>&, int);
void cut_rod_with_tabulation(vector<int>&, int);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> rod_price_table {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

    int rod_length = 4;
    cout << "Recursive approach : " << recursive_cut_rod(rod_price_table, rod_length) << "\n";
    cout << "Dynamic programming approach : " << dp_cut_rod(rod_price_table, rod_length) << "\n";

    cout << "\nCutting method : ";
    cut_rod_with_tabulation(rod_price_table, rod_length);

    return 0;
}

int recursive_cut_rod(vector<int>& price_table, int length)
{
    if(length == 0)
        return 0;
    
    int max_value = 0;
    for(int i = 0; i < length; ++i)
        max_value = max(max_value, price_table[i] + recursive_cut_rod(price_table, length - (i + 1)));
    
    return max_value;
}

// Bottom-Up 
int dp_cut_rod(vector<int>& price_table, int length)
{
    vector<int> dp_table(length + 1, 0);

    for(int i = 1; i <= length; ++i)
    {
        int max_value = 0;
        for(int j = 0; j < i; ++j)
            max_value = max(max_value, price_table[j] + dp_table[i - j - 1]);
        
        dp_table[i] = max_value;
    }

    return dp_table[length];
}

void cut_rod_with_tabulation(vector<int>& price_table, int length)
{
    vector<int> dp_table(length + 1, 0);
    vector<int> cut(length + 1, 0);

    for(int i = 1; i <= length; ++i)
    {
        int max_value = 0;
        for(int j = 0; j < i; ++j)
        {
            if(max_value < price_table[j] + dp_table[i - j - 1])
            {
                max_value = price_table[j] + dp_table[i - j - 1];
                cut[i] = j + 1;
            }
        }
        
        dp_table[i] = max_value;
    }

    while(length > 0)
    {
        cout << cut[length] << " ";
        length -= cut[length];
    }

    cout << "\n";
}