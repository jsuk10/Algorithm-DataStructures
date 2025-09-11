
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxNum = 100;

vector<long long> dp(maxNum + 1, 0);

void memo()
{
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    for (int i = 6; i <= 100; i++)
    {
        dp[i] = dp[i - 5] + dp[i - 1];
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);

    int n, a;
    cin >> n;
    memo();

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        cout << dp[a] << "\n";
    }

    return 0;
}