#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[51][51] = {0};
int visited[51][51] = {0};
int m, n, t, k, tempX, tempY, ans;
int arrX[] = {1, -1, 0, 0},
    arrY[] = {0, 0, 1, -1};


void BFS(int y, int x)
{
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        if (map[y + arrY[i]][x + arrX[i]] == 1 && visited[y + arrY[i]][x + arrX[i]] == 0)
        {
            BFS(y + arrY[i], x + arrX[i]);
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> t;
    for (int num = 0; num < t; num++)
    {

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                map[i][j] = 0;
                visited[i][j] = 0;
            }
        ans = 0;
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++)
        {
            cin >> tempX >> tempY;
            map[tempY][tempX] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] == 1 && visited[i][j] == 0)
                {
                    ans++;
                    BFS(i, j);
                }
            }
        }
        cout << ans << "\n";
    }
}