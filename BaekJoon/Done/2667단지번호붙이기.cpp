
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ans;
char map[26][26];
int visited[26][26];
int n, temp, counts = 0;
int arrX[] = {1, -1, 0, 0},
    arrY[] = {0, 0, 1, -1};

void DFS(int y, int x)
{
    counts++;
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        if (visited[y + arrY[i]][x + arrX[i]] == 0 && map[y + arrY[i]][x + arrX[i]] == '1')
        {
            DFS(y + arrY[i], x + arrX[i]);
        }
    }
}

void Process()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == '1' && visited[i][j] == 0)
            {
                counts = 0;
                DFS(i, j);
                ans.push_back(counts);
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            visited[i][j] = 0;
        }
    }

    Process();
}