#include<iostream>
#include<vector>

#define MINSUM -1e4

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maximum_subarray(nums, 0, nums.size() - 1);
    }

    int maximum_subarray(vector<int> &arr, int l, int r)
    {
        if(l == r)
            return arr[l];
        
        int mid = (l + r) / 2;
        int l_sum = maximum_subarray(arr, l, mid);
        int r_sum = maximum_subarray(arr, mid + 1, r);
        int cross_sum = maximum_cross_sum(arr, l, mid, r);

        return max(l_sum, max(r_sum, cross_sum));
    }

    int maximum_cross_sum(vector<int> &arr, int l, int k, int r)
    {
        int left_max = MINSUM;
        int sum = 0;
        for(int i = k; i >= l; --i)
        {
            sum += arr[i];

            if(sum > left_max)
                left_max = sum;
        }

        int right_max = MINSUM;
        sum = 0;
        for(int i = k; i < r + 1; ++i)
        {
            sum += arr[i];

            if(sum > right_max)
                right_max = sum;
        }

        return max(left_max + right_max - arr[k], max(left_max, right_max));
    }
};

int main(void)
{
    vector<int> nums;
    int data;

    while(cin >> data)
        nums.push_back(data);

    Solution sol;
    cout << sol.maxSubArray(nums) << endl;

    return 0;
}