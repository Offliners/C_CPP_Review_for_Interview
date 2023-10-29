#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = n * m - 1;

        while(low <= high)
        {
            int mid = (low + high) / 2;
            int row = mid / m;
            int col = mid % m;

            if(matrix[row][col] == target)
                return true;
            
            if(matrix[row][col] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return false;
    }
};

int main(void)
{
    int data;
    string row_str;
    vector<vector<int>> mat;

    getline(cin, row_str);
    int target = stoi(row_str);

    while(getline(cin, row_str))
    {
        vector<int> row;
        stringstream ss(row_str);
        string num;
        while(getline(ss, num, ' '))
            row.push_back(stoi(num));

        mat.push_back(row);
    }

    Solution sol;
    
    if(sol.searchMatrix(mat, target))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}