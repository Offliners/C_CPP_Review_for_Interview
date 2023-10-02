#include<iostream>
#include<vector>

using namespace std;

int dc_bitonic_champion_problem(vector<int>&, int, int);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> bitonic_data{3, 7, 9, 17, 35, 28, 21, 18, 6, 4};

    int index = dc_bitonic_champion_problem(bitonic_data, 0, bitonic_data.size() - 1);
    cout << "Champion index : " << index << "\n";
    cout << "Champion value : " << bitonic_data[index] << "\n";

    return 0;
}

int dc_bitonic_champion_problem(vector<int> &data, int l, int r)
{
    if(l == r)
        return l;
    else
    {
        int mid = (l + r) / 2;
        int l_max = dc_bitonic_champion_problem(data, l, mid);
        int r_max = dc_bitonic_champion_problem(data, mid + 1, r);

        if(data[l_max] >= data[r_max])
            return l_max;

        if(data[l_max] < data[r_max])
            return r_max;
    }
}