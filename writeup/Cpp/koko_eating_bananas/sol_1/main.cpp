#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxK = *max_element(piles.begin(), piles.end());
        for(int k = 1; k <= maxK; ++k)
        {
            long long int count = 0;
            for(int i = 0; i < piles.size(); ++i)
                count += (piles[i] % k == 0) ? piles[i] / k : piles[i] / k + 1;
            
            if(count <= h)
                return k;
        }

        return -1;
    }
};

int main(void)
{
    int h;
    cin >> h;

    int data;
    vector<int> piles;
    while(cin >> data)
        piles.push_back(data);

    Solution sol;
    cout << sol.minEatingSpeed(piles, h) << endl;

    return 0;
}