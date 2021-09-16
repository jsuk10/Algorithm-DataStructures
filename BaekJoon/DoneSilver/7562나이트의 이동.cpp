
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Position
{
    int x, y;
    Position(int y, int x) : x(x), y(y){};
};

int n, testSize;
int arrX[8] = {1, 2, 2, 1, -1, -2, -2, -1},
    arrY[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

void chess()
{
    cin >> n;
    vector<int> map[n];
    queue<Position> q;

    int startX, endX, startY, endY;
    cin >> startX >> startY >> endX >> endY;

    q.push(Position(startY, startX));

    for (int i = 0; i < n; i++)
    {
        map[i].clear();
        for (int j = 0; j < n; j++)
            map[i].push_back(0);
    }

    map[startY][startX] = 1;

    while (map[endY][endX] == 0)
    {

        Position temp = q.front();
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int tempX = temp.x + arrX[i];
            int tempY = temp.y + arrY[i];

            if (tempX >= 0 && tempX < n &&
                tempY >= 0 && tempY < n &&
                map[tempY][tempX] == 0)
            {
                // cout << tempX << ": " << tempY << "\n";
                q.push(Position(tempY, tempX));
                map[tempY][tempX] = map[temp.y][temp.x] + 1;
            }
        }
    }

    cout << map[endY][endX] - 1 << "\n";
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> testSize;
    for (int i = 0; i < testSize; i++)
    {
        chess();
    }
}