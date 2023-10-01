#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 1)
            return;

        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == 0)
            {
                int swap_index = i + 1;
                bool all_zero = true;
                for(int j = i + 1; j < nums.size(); ++j)
                {
                    if(nums[j] != 0)
                    {
                        swap_index = j;
                        all_zero = false;
                        break;
                    }
                    else
                        all_zero = true;
                }

                if(!all_zero)
                {
                    int temp = nums[swap_index];
                    nums[swap_index] = nums[i];
                    nums[i] = temp;
                }
            }
        }
    }
};

int main(void)
{
    Solution sol;
    int data;
    vector<int> nums;

    while(cin >> data)
        nums.push_back(data);

    sol.moveZeroes(nums);
    for(int i = 0; i < nums.size() - 1; ++i)
        cout << nums[i] << " ";
    cout << nums.back() << endl;

    return 0;
}