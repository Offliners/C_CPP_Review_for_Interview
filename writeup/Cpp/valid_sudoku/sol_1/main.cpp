#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int stride = 3;
        for(int i = 0; i < board.size(); i += stride)
        {
            for(int j = 0; j < board[i].size(); j += stride)
            {
                vector<int> check(9, 0);
                for(int row = i; row < i + stride; ++row)
                    for(int col = j; col < j + stride; ++col)
                        if(board[row][col] != '.')
                            check[(board[row][col] - '0') - 1] += 1;

                for(int k = 0; k < check.size(); ++k)
                    if(check[k] > 1)
                        return false;
            }
        }

        for(int i = 0; i < board.size(); ++i)
        {
            vector<int> check(9, 0);
            for(int j = 0; j < board[i].size(); ++j)
                if(board[i][j] != '.')
                    check[(board[i][j] - '0') - 1] += 1;

            for(int k = 0; k < check.size(); ++k)
                if(check[k] > 1)
                    return false;
        }

        int index = 0;
        for(int j = 0; j < board[index].size(); ++j)
        {
            vector<int> check(9, 0);
            for(int i = 0; i < board.size(); ++i)
                if(board[i][j] != '.')
                    check[(board[i][j] - '0') - 1] += 1;

            for(int k = 0; k < check.size(); ++k)
                if(check[k] > 1)
                    return false;

            ++index;
        }

        return true;
    }
};


int main(void)
{
    string row_str;
    vector<vector<char>> board;

    while(getline(cin, row_str))
    {
        vector<char> row;
        stringstream ss(row_str);
        string c;
        while(getline(ss, c, ' '))
            row.push_back(c[0]);

        board.push_back(row);
    }

    Solution sol;
    if(sol.isValidSudoku(board))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}