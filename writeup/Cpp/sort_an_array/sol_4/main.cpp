#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        nums.insert(nums.begin(), 0);
        BuildMaxHeap(nums);

        int size = nums.size() - 1;
        for(int i = nums.size() - 1; i >= 2; --i)
        {
            int temp = nums[1];
            nums[1] = nums[i];
            nums[i] = temp;
            --size;
            MaxHeapify(nums, 1, size);
        }

        nums.erase(nums.begin()); 

        return nums;
    }

    void MaxHeapify(vector<int>& nums, int root, int length){
        int left = 2 * root;
        int right = 2 * root + 1;
        int largest;

        if(left <= length && nums[left] > nums[root])
            largest = left;
        else
            largest = root;

        if(right <= length && nums[right] > nums[largest])
            largest = right;

        if(largest != root)
        {
            int temp = nums[largest];
            nums[largest] = nums[root];
            nums[root] = temp;
            MaxHeapify(nums, largest, length);
        }
    }

    void BuildMaxHeap(vector<int> &nums)
    {
        for(int i = nums.size() / 2; i >= 1 ; i--)
            MaxHeapify(nums, i, nums.size() - 1);
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