#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void greedy_coin_changing_problem(vector<int>&, vector<int>&, int);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 9;
    vector<int> denomination{1, 5, 10, 50};
    vector<int> select;

    greedy_coin_changing_problem(select, denomination, n);

    cout << "Mimimnm number of change for " << n << " is " << select.size() << "\n";
    cout << "Select method : ";    
    for(auto it = select.begin(); it != select.end(); ++it)
        cout << *it << " ";
    cout << "\n";

    return 0;
}

void greedy_coin_changing_problem(vector<int> &select, vector<int> &denomination, int n)
{
    sort(denomination.begin(), denomination.end());

    for(int i = denomination.size() - 1; i >= 0; --i)
    {
        while(n >= denomination[i])
        {
            n -= denomination[i];
            select.push_back(denomination[i]);
        }
    }
}