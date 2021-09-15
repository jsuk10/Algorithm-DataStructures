
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

char map[101][101];
int visited[101][101];
int n, m, x, y;
int arrX[] = {1, 0, -1, 0},
    arrY[] = {0, 1, 0, -1};

queue<pair<int, int>> q;

void BFS()
{
    pair<int, int> temp = make_pair(0, 0);
    visited[0][0] = 1;
    q.push(temp);
    while (!q.empty())
    {
        temp = q.front();
        x = temp.first;
        y = temp.second;
        q.pop();
        for (int i = 3; i >= 0; i--)
        {
            int tempX = x + arrX[i], tempY = y + arrY[i];

            if (tempX >= 0 && tempX < m && tempY >= 0 && tempY < n && map[tempY][tempX] == '1' && visited[tempY][tempX] == 0)
            {
                visited[tempY][tempX] = visited[y][x] + 1;
                temp = make_pair(tempX, tempY);
                q.push(temp);
            }
        }
    }
    cout << visited[n - 1][m - 1];
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    BFS();
}