#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstring>
#include <deque>
#include <stack>
#include <string>
#include <string_view>
#include <utility>
#include <queue>
#include <cmath>

using namespace std;

class Solution
{
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        if (i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] == '0')
            return;

        grid[i][j] = '0'; // 방문 처리

        // 상, 하, 좌, 우 탐색
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
int main()
{
    vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // vector<string> v2 = {"bab", "dab", "cab"};
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};

    auto c = Solution().numIslands(grid);

    // for (auto b : c)
    // {
    //     cout << b << endl;
    // }

    cout << c << endl;
    return 0;
}