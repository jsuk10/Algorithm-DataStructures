
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct postion
{
    int x;
    int y;
    int z;

    postion(int z, int y, int x) : x(x), y(y), z(z) {}
};

vector<int> map[101][101];
postion tempP = postion(1, 1, 1);
int x, y, z, temp, ans;
int arrX[6] = {1, 0, -1, 0, 0, 0},
    arrY[6] = {0, 1, 0, -1, 0, 0},
    arrZ[6] = {0, 0, 0, 0, 1, -1};
queue<postion> q;

void check()
{
    for (int i = 0; i < z; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < x; k++)
            {
                if (map[i][j][k] == 0)
                {
                    cout << "-1";
                    return;
                }
                ans = max(ans, map[i][j][k]);
            }
        }
    }
    cout << ans - 1;
}

void tomato()
{
    while (!q.empty())
    {
        tempP = q.front();
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int tempZ = tempP.z + arrZ[i];
            int tempY = tempP.y + arrY[i];
            int tempX = tempP.x + arrX[i];
            if (tempZ >= 0 && tempZ < z &&
                tempY >= 0 && tempY < y &&
                tempX >= 0 && tempX < x && map[tempZ][tempY][tempX] == 0)
            {
                map[tempZ][tempY][tempX] = map[tempP.z][tempP.y][tempP.x] + 1;
                postion tempP2 = postion(tempZ, tempY, tempX);
                q.push(tempP2);
            }
        }
    }
    check();
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> x >> y >> z;
    for (int i = 0; i < z; i++)
        for (int j = 0; j < y; j++)
            for (int k = 0; k < x; k++)
            {
                cin >> temp;
                map[i][j].push_back(temp);
                if (temp == 1)
                {
                    tempP = postion(i, j, k);
                    q.push(tempP);
                }
            }
    tomato();
}