#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> table(n + 1, 0);

        int offset = 1;
        for(int i = 1; i <= n; ++i)
        {
            if(offset * 2 == i)
                offset = i;
            
            table[i] = 1 + table[i - offset];
        }

        return table;
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