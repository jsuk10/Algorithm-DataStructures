
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int MOD = 1000000000;

struct Position
{
    Position(int x, int y, int z) : x(x), y(y), z(z) {}
    int x = 0, y = 0, z = 0;
};

int arrx[6] = {1, -1, 0, 0, 0, 0};
int arry[6] = {0, 0, 1, -1, 0, 0};
int arrz[6] = {0, 0, 0, 0, 1, -1};

int main()
{
    freopen("input.txt", "r", stdin);

    int x, y, z;
    cin >> x >> y >> z;
    vector<vector<vector<int>>> array(z, vector<vector<int>>(y, (vector<int>(x, 0))));
    queue<Position> startPoint;
    for (int i = 0; i < z; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < x; k++)
            {
                cin >> array[i][j][k];
                if (array[i][j][k] == 1)
                {
                    startPoint.push({k, j, i});
                }
            }
        }
    }

    int count = 0;
    while (!startPoint.empty())
    {
        auto position = startPoint.front();
        startPoint.pop();
        for (int i = 0; i < 6; i++)
        {
            Position temp = {position.x + arrx[i], position.y + arry[i], position.z + arrz[i]};
            if (temp.x >= 0 && temp.x < x && temp.y >= 0 && temp.y < y && temp.z >= 0 && temp.z < z && array[temp.z][temp.y][temp.x] == 0)
            {
                array[temp.z][temp.y][temp.x] = array[position.z][position.y][position.x] + 1;
                startPoint.push(temp);
            }
        }
    }
    int ans = 1;

    for (auto a : array)
    {
        for (auto b : a)
        {
            for (auto c : b)
            {
                if (c == 0)
                {
                    cout << -1;
                    return 0;
                }
                ans = max(ans, c);
            }
        }
    }
    cout << ans - 1;

    return 0;
}