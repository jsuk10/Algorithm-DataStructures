
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int number, edgeCount, startEdge, endEdge, ans = 0;
int visited[101] = {0};
vector<int> edge[101];
queue<int> q;

void BFS(int index)
{
    q.push(index);
    visited[1] = 1;
    while (!q.empty())
    {
        index = q.front();
        q.pop();
        for (int i = 0; i < edge[index].size(); i++)
        {
            if (visited[edge[index][i]] == 1)
                continue;
            visited[edge[index][i]] = 1;
            ans++;
            q.push(edge[index][i]);
        }
    }
    cout << ans;
}

void DFS(int index)
{
    visited[index] = 1;
    for (int i = 0; i < edge[index].size(); i++)
    {
        if (visited[edge[index][i]] == 1)
            continue;
        ans++;
        DFS(edge[index][i]);
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    cin >> number >> edgeCount;
    for (int j = 0; j < edgeCount; j++)
    {
        cin >> startEdge >> endEdge;
        edge[startEdge].push_back(endEdge);
        edge[endEdge].push_back(startEdge);
    }
    DFS(1);
    cout << ans;

    return 0;
}