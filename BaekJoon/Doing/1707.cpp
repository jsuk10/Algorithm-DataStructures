
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

//비연결 리스트도 판별 해줘야한다.

using namespace std;

int testCase, tempV, tempE, startPoint, endPoint, index, color = 1;

void Porcess()
{
    cin >> tempV >> tempE;
    vector<int> e[tempV + 1];
    queue<int> q;
    int map[tempV + 1] = {0};

    for (int i = 0; i < tempE; i++)
    {
        cin >> startPoint >> endPoint;
        e[startPoint].push_back(endPoint);
        e[endPoint].push_back(startPoint);
    }
    map[1] = 1;
    q.push(1);
    while (!q.empty())
    {
        index = q.front();
        q.pop();
        // if (map[index] != 0)
        //     continue;
        color = (color == 1) ? 2 : 1;
        for (int i = 0; i < e[index].size(); i++)
        {
            //방문전이라면
            if (map[e[index][i]] == 0)
            {
                //색으로 칠해줌
                map[e[index][i]] = color;
                //갈수있게 넣어줌
                q.push(e[index][i]);
            }
            //이미 칠해졌는데 색이 다르면?
            else if (map[e[index][i]] != color)
            {
                cout << "No\n";
                return;
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