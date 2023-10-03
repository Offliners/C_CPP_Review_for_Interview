#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());

        for(int i = 0; i < matrix.size(); ++i)
            for(int j = 0; j < i; ++j)
                swap(matrix[i][j], matrix[j][i]);
    }
};

int main(void)
{
    int data;
    string row_str;
    vector<vector<int>> mat;

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
    sol.rotate(mat);

    for(int i = 0; i < mat.size(); ++i)
    {
        for(int j = 0; j < mat[i].size() - 1; ++j)
            cout << mat[i][j] << " ";

        cout << mat[i].back()<< endl;
    }

    return 0;
}