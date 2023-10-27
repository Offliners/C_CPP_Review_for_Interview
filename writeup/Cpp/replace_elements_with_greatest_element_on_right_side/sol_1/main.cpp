#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
    public:
        vector<int> replaceElements(vector<int>& arr)
        {
            vector<int> ans;
            for(int i = 0; i < arr.size(); ++i)
            {
                if(i == arr.size() - 1)
                    ans.push_back(-1);
                else
                    ans.push_back(*max_element(arr.begin() + i + 1, arr.end()));
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