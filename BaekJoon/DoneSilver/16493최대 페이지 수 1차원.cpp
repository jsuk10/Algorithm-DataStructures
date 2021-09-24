
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int day, chabter, ans = 0;
int willday[22], pages[21], dp[202];

void PrintDP()
{
    for (int j = 0; j <= day; j++)
        cout << dp[j] << " ";
    cout << "\n";
}

void process()
{
    for (int i = 0; i < chabter; i++)
    {
        for (int j = day; j > 0; j--)
        {
            if (j - willday[i] >= 0)
                dp[j] = max(dp[j], dp[j - willday[i]] + pages[i]);
        }
    }
    cout << dp[day];
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