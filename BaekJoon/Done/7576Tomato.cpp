#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

vector<vector<int> > map;
queue<pair<int,int> > q;

int xarr[4] = {-1,1,0,0};
int yarr[4] = {0,0,-1,1};

int n, m, temp, answer;


void checkMap(){
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++){
            if(map[i][j] == 0){
                answer = 0;
                return;
            }
            answer = (map[i][j] > answer)? map[i][j] : answer;
        }
    }
}

void Tomamto()
{
    int count = 0;
    while (!q.empty())
    {
        int x = q.front().second ,y = q.front().first;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){

            if(x + xarr[i] >= 0 && x + xarr[i] < n &&
            y + yarr[i] >= 0 && y + yarr[i] < m 
            && map[y + yarr[i]][x + xarr[i]] == 0){
                map[y + yarr[i]][x + xarr[i]] = map[y][x] + 1;
                q.push(make_pair(y + yarr[i], x + xarr[i]));
            }
        }
    }
}


int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        vector<int> tempV;
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            tempV.push_back(temp);

            if (temp == 1)
            {
                //y, x저장
                q.push(make_pair(i, j));
            }
        }
        map.push_back(tempV);
    }
    Tomamto();
    checkMap();
    cout << answer-1;
}