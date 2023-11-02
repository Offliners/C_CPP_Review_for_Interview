#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        
        sort(nums.begin(), nums.end());
        for(int i = 1; i <= nums.size(); ++i)
        {
            bool flag = false;
            int front = 0;
            int end = nums.size() - 1;

            while(front <= end)
            {
                int mid = front + (end - front) / 2;
                if(nums[mid] == i)
                {
                    flag = true;
                    break;
                }
                else if(nums[mid] < i)
                    front = mid + 1;
                else
                    end = mid - 1;
            }

            if(!flag)
                ans.push_back(i);
        }

        return ans;
    }
};

int main(void)
{
    Solution sol;
    int data;
    vector<int> nums;

    while(cin >> data)
        nums.push_back(data);

    vector<int> ans = sol.findDisappearedNumbers(nums);

    if(ans.size() != 0)
    {
        for(int i = 0; i < ans.size() - 1; ++i)
            cout << ans[i] << " ";

        cout << ans.back() << endl;
    }
    
    return 0;
}