
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Point
{
    int x, y, breakWall;
    Point(int y, int x, int breakWall) : y(y), x(x), breakWall(breakWall) {}
};

char map[1001][1001];
int x, y, visited[1001][1001][2];
int arrX[4] = {1, -1, 0, 0}, arrY[4] = {0, 0, 1, -1};

void printMap()
{
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
            cout << map[i][j] << " ";
        cout << "\n";
    }
}

void printVisited()
{
    cout << "\n0의 세계\n";
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
            cout << visited[i][j][0] << " ";
        cout << "\n";
    }
    cout << "\n1의 세계\n";
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
            cout << visited[i][j][1] << " ";
        cout << "\n";
    }
}

int Process()
{
    queue<Point> q;
    q.push(Point(0, 0, 0));
    visited[0][0][0] = 1;

    while (!q.empty())
    {
        Point p = q.front();
        q.pop();

        if (p.y == y - 1 && p.x == x - 1)
            return visited[p.y][p.x][p.breakWall];

        for (int i = 0; i < 4; i++)
        {
            //x,y가 범위를 안넘어가고 이전에 방문한기록이 없을경우
            Point newPoint(p.y + arrY[i], p.x + arrX[i], p.breakWall);

            if (newPoint.x >= 0 && newPoint.x < x &&
                newPoint.y >= 0 && newPoint.y < y &&
                visited[newPoint.y][newPoint.x][newPoint.breakWall] == 0)
            {
                //벽 만난 경우
                if (map[newPoint.y][newPoint.x] == '1')
                {
                    //부셨는데 벽 만나는 경우
                    if (newPoint.breakWall == 1)
                        continue;
                    //부시기 전에 벽 만날 경우, 부신 세계 진입
                    else
                        visited[newPoint.y][newPoint.x][++newPoint.breakWall] = visited[p.y][p.x][p.breakWall] + 1;
                }
                //벽 아닌 경우
                else
                {
                    visited[newPoint.y][newPoint.x][newPoint.breakWall] = visited[p.y][p.x][p.breakWall] + 1;
                }
                q.push(newPoint);
            }
        }
    }
    return -1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> y >> x;
    for (int i = 0; i < y; i++)
        for (int j = 0; j < x; j++)
            cin >> map[i][j];
    cout << Process();
    printVisited();
}