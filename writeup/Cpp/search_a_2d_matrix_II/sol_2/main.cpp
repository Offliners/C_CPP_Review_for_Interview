#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = matrix[0].size() - 1;

        while(row <= matrix.size() - 1 && col >= 0)
        {
            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] > target)
                --col;
            else if(matrix[row][col] < target)
                ++row;
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