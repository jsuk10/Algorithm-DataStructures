
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int MOD = 1000000000;

int main()
{
    freopen("input.txt", "r", stdin);

    int row, col;
    cin >> col >> row;
    vector<vector<int>> array(row, vector<int>(col, 0));
    queue<pair<int, int>> startPoint;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> array[i][j];

            if (array[i][j] == 1)
            {
                array[i][j] = 0;
                startPoint.push({i, j}); // 익은 토마토 좌표 push
            }
        }
    }

    int count = 0;
    while (!startPoint.empty())
    {
        count++;
        int size = startPoint.size();
        for (int i = 0; i < size; i++)
        {
            auto pair = startPoint.front();
            startPoint.pop();
            int y = pair.second;
            int x = pair.first;
            if (x < 0 || x >= array.size())
            {
                continue;
            }
            if (y < 0 || y >= array[x].size())
            {
                continue;
            }
            if (array[x][y] != 0)
            {
                continue;
            }
            array[x][y] = count;
            startPoint.push({x + 1, y});
            startPoint.push({x - 1, y});
            startPoint.push({x, y + 1});
            startPoint.push({x, y - 1});
        }
    }
    int ans = 1;
    for (auto &a : array)
    {
        for (auto &b : a)
        {
            if (b == 0)
            {
                cout << -1;
                return 0;
            }
            else
            {
                ans = max(ans, b);
            }
        }
    }
    cout << ans - 1;

    return 0;
}