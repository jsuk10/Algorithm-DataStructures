
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

int testCase, tempV, tempE, startPoint, endPoint, indexs, color = 1;

void Porcess()
{
    cin >> tempV >> tempE;
    //간선들
    vector<int> e[tempV + 1];
    //bfs의 queue
    queue<int> q;
    //방문했는지 체크하는 맵
    int *map = new int[tempV + 1];

    memset(map, 0, (tempV + 1) * sizeof(int));

    //간선 추가
    for (int i = 0; i < tempE; i++)
    {
        cin >> startPoint >> endPoint;
        e[startPoint].push_back(endPoint);
        e[endPoint].push_back(startPoint);
    }
    //연결되지 않은 정점(비연결 리스트) 있을수도 있으니 for문으로 정점 돌려서 찾아봄.
    //ex) 1 - 2 - 3 4 도 이분 그래프
    for (int j = 1; j <= tempV; j++)
    {
        //칠해져 있으면 continue;
        if (map[j] != 0)
            continue;
        //안칠해지면 색칠하고 queue에 넣음
        map[j] = color;
        q.push(j);
        //BFS
        while (!q.empty())
        {
            indexs = q.front();
            q.pop();
            color = (map[indexs] == 1) ? 2 : 1;
            for (int i = 0; i < e[indexs].size(); i++)
            {
                //방문전이라면
                if (map[e[indexs][i]] == 0)
                {
                    //색으로 칠해줌
                    map[e[indexs][i]] = color;
                    //갈수있게 넣어줌
                    q.push(e[indexs][i]);
                }
                //이미 칠해졌는데 색이 다르면?
                else if (map[e[indexs][i]] != color)
                {
                    cout << "NO\n";

                    return;
                }
            }
        }
    }
    cout << "YES\n";

    return;
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        color = 1;
        Porcess();
    }
}