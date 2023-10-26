#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1); 

        return nums;
    }

    void merge(vector<int>& nums, int const left, int const mid, int const right)
    {
        int const subArrayOne = mid - left + 1;
        int const subArrayTwo = right - mid;
 
        vector<int> leftArray(subArrayOne);
        vector<int> rightArray(subArrayTwo);

        for(int i = 0; i < subArrayOne; ++i)
            leftArray[i] = nums[left + i];
            
        for(int j = 0; j < subArrayTwo; ++j)
            rightArray[j] = nums[mid + 1 + j];
    
        auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
        int indexOfMergedArray = left;
    
        while(indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
        {
            if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
            {
                nums[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                ++indexOfSubArrayOne;
            }
            else
            {
                nums[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                ++indexOfSubArrayTwo;
            }
            ++indexOfMergedArray;
        }
    
        while(indexOfSubArrayOne < subArrayOne)
        {
            nums[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            ++indexOfSubArrayOne;
            ++indexOfMergedArray;
        }
    
        while(indexOfSubArrayTwo < subArrayTwo)
        {
            nums[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            ++indexOfSubArrayTwo;
            ++indexOfMergedArray;
        }
    }
    
    void mergeSort(vector<int>& nums, int const begin, int const end)
    {
        if (begin >= end)
            return;
    
        int mid = begin + (end - begin) / 2;
        mergeSort(nums, begin, mid);
        mergeSort(nums, mid + 1, end);
        merge(nums, begin, mid, end);
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