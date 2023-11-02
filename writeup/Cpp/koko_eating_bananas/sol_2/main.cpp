#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int front = 1;
        int end = *max_element(piles.begin(), piles.end());

        int ans = end;
        while(front <= end)
        {
            int mid = front + (end - front) / 2;
            long long int count = 0;
            for(int i = 0; i < piles.size(); ++i)
                count += (piles[i] % mid == 0) ? piles[i] / mid : piles[i] / mid + 1;

            if(count <= h)
            {
                ans = mid;
                end = mid - 1;
            }
            else
                front = mid + 1;
        }

        return ans;
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