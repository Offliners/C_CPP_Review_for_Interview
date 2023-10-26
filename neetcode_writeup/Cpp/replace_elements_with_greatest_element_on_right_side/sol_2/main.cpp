#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
    public:
        vector<int> replaceElements(vector<int>& arr)
        {
            vector<int> ans(arr.size());
            int right_num = -1;
            for(int i = arr.size() - 1; i >= 0; --i)
            {
                ans[i] = right_num;
                if(arr[i] > right_num)
                    right_num = arr[i];                
            }

            return ans;
        }
};

int main(void)
{
    int data;
    vector<int> nums;
    Solution sol;

    while(cin >> data)
        nums.push_back(data);
    
    vector<int> ans = sol.replaceElements(nums);
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << endl; 

    return 0;
}