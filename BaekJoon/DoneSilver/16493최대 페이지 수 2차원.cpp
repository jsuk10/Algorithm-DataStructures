
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int day, chabter, ans = 0;
int willday[22], pages[21], dp[21][202];

void PrintDP()
{
    for (int i = 0; i < chabter; i++)
    {
        for (int j = 1; j <= day; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }
}

void process()
{
    for (int j = willday[0]; j <= day; j++)
    {
        dp[0][j] = pages[0];
    }
    for (int i = 1; i < chabter; i++)
    {
        for (int j = 0; j <= day; j++)
        {
            if (j - willday[i] >= 0)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - willday[i]] + pages[i]);
            else
                dp[i][j] = dp[i - 1][j];
            ans = max(dp[i][j], ans);
        }
    }
    PrintDP();
    cout << dp[chabter - 1][day];
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> day >> chabter;
    for (int i = 0; i < chabter; i++)
    {
        cin >> willday[i] >> pages[i];
    }
    process();
}