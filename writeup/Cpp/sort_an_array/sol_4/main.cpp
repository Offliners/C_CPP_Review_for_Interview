#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size() - 1);

        return nums;
    }

    void quick_sort(vector<int>& nums, int front, int end) {
        if(front < end)
        {
            int pivot = partition(nums, front, end);
            quick_sort(nums, front, pivot - 1);
            quick_sort(nums, pivot + 1, end);
        }
    }

    int partition(vector<int>& nums, int front, int end) {
        int pivot = nums[end];
        int i = front - 1;

        for(int j = front; j < end; ++j)
        {
            if(nums[j] < pivot)
            {
                ++i;
                swap(nums[i], nums[j]);
            }
        }

        ++i;
        swap(nums[i], nums[end]);

        return i;
    }

    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

};

int main(void)
{
    int data;
    vector<int> nums;
    Solution sol;

    while(cin >> data)
        nums.push_back(data);
    
    vector<int> ans = sol.sortArray(nums);
    for(int i = 0; i < ans.size() - 1; ++i)
        cout << ans[i] << " ";

    cout << ans.back() << endl;

    return 0;
}