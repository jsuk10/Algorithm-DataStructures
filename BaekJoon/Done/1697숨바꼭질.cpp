
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;
int map[100001] = {0};
queue<int> q;

void move()
{
    q.push(n);
    map[n] = 1;
    while (map[k] == 0)
    {
        int item = q.front();
        q.pop();
        if (item + 1 < 100001 && map[item + 1] == 0)
        {
            map[item + 1] = map[item] + 1;
            q.push(item + 1);
        }
        if (item - 1 >= 0 && map[item - 1] == 0)
        {
            map[item - 1] = map[item] + 1;
            q.push(item - 1);
        }
        if (item * 2 < 100001 && map[item * 2] == 0)
        {
            map[item * 2] = map[item] + 1;
            q.push(item * 2);
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n >> k;
    move();

    cout << map[k] - 1;
}