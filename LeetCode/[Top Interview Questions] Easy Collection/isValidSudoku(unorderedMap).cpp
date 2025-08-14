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
        unordered_map<int, unordered_set<char>> boardrow;
        unordered_map<int, unordered_set<char>> boardcol;
        unordered_map<int, unordered_set<char>> boardnine;
        
        for (auto row = 0; row < board.size(); row++)
        {
            for (auto col = 0; col < board[0].size(); col++)
            {
                char ch = board[row][col];
                if (ch == '.')
                    continue;

                if (boardrow[row].find(ch) == boardrow[row].end())
                {
                    boardrow[row].insert(ch);
                }
                else
                {
                    return false;
                }

                if (boardcol[col].find(ch) == boardcol[col].end())
                {
                    boardcol[col].insert(ch);
                }
                else
                {
                    return false;
                }
                int nineIndex = (row / 3) * 3 + (col / 3);
                if (boardnine[nineIndex].find(ch) == boardnine[nineIndex].end())
                {
                    boardnine[nineIndex].insert(ch);
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};