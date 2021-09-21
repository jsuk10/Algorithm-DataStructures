
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct People
{
    int hp, joy;
    People(int hp, int joy) : hp(hp), joy(joy){};
};

int number, indexs = 1, ans = 0;
int hp[21], joy[21], dp[21][101];
vector<People> v;

bool Psort(People a, People b)
{
    return a.hp < b.hp;
}

void Process()
{
    for (int i = v[0].hp; i < 100; i++)
        dp[0][i] = v[0].joy;
    if (v[0].hp < 100)
        ans = v[0].joy;
    for (int i = 1; i < v.size(); i++)
    {
        dp[i][v[i].hp] = v[i].joy;
        for (int j = 1; j < 100; j++)
        {
            if (j < v[i].hp)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j - v[i].hp] + v[i].joy, dp[i - 1][j]);
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> number;
    for (int i = 0; i < number; i++)
        cin >> hp[i];
    for (int i = 0; i < number; i++)
        cin >> joy[i];

    for (int i = 0; i < number; i++)
        v.push_back(People(hp[i], joy[i]));
    sort(v.begin(), v.end(), Psort);
    Process();
}