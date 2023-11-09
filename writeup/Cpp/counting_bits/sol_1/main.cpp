#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);

        for(int i = 0; i <= n; ++i)
        {
            int temp = i;
            while(temp > 0)
            {
                temp &= (temp - 1);
                ans[i] += 1;
            }
        }

        return ans;
    }
};

int main(void)
{
    int n;
    cin >> n;

    Solution sol;
    vector<int> ans = sol.countBits(n);
    for(int i = 0; i < ans.size() - 1; ++i)
        cout << ans[i] << " ";
    cout << ans.back() << endl;

    return 0;
}