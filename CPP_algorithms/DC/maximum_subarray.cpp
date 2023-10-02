#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int dc_maximum_subarray(vector<int>&, int, int);
int maximum_cross_sum(vector<int>&, int, int, int);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> data{1, -2, 7, -4, 6, -3};
    cout << "Maximum subarray sum is : " << dc_maximum_subarray(data, 0, data.size() - 1) << "\n";

    return 0;
}

int dc_maximum_subarray(vector<int> &arr, int l, int r)
{
    if(l == r)
        return arr[l];
    
    int mid = (l + r) / 2;
    int l_sum = dc_maximum_subarray(arr, l, mid);
    int r_sum = dc_maximum_subarray(arr, mid + 1, r);
    int cross_sum = maximum_cross_sum(arr, l, mid, r);

    return max(l_sum, max(r_sum, cross_sum));
}

int maximum_cross_sum(vector<int> &arr, int l, int k, int r)
{
    int left_max = INT_MIN;
    int sum = 0;
    for(int i = k; i >= l; --i)
    {
        sum += arr[i];

        if(sum > left_max)
            left_max = sum;
    }

    int right_max = INT_MIN;
    sum = 0;
    for(int i = k; i < r + 1; ++i)
    {
        sum += arr[i];

        if(sum > right_max)
            right_max = sum;
    }

    return max(left_max + right_max - arr[k], max(left_max, right_max));
}