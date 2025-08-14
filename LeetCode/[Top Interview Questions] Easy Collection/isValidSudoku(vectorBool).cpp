#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> boardrow (9, vector<bool>(9, false));
        vector<vector<bool>> boardcol (9, vector<bool>(9, false));
        vector<vector<bool>> boardnine (9, vector<bool>(9, false));

        for (auto row = 0; row < board.size(); row++)
        {
            for (auto col = 0; col < board[0].size(); col++)
            {
                if (board[row][col] == '.') continue;

                // vector size is 9. so convert 0 ~ 8
                int num = board[row][col] - '1';

                int nineIndex = (row / 3) * 3 + (col / 3);

                if (boardrow[row][num] || boardcol[col][num] || boardnine[nineIndex][num])
                    return false;
                else
                {
                    boardrow[row][num] = boardcol[col][num] = boardnine[nineIndex][num] = true;
                }
            }
        }
        return true;
    }
};