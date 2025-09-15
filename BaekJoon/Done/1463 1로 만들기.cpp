
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxNum = 1000000;

vector<int> dp(maxNum, 0);

int main()
{
    // freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        int a = INT_MAX;
        if (i % 3 == 0)
        {
            a = dp[i / 3] + 1;
        }

        if (i % 2 == 0)
        {
            a = min(dp[i / 2] + 1, a);
        }

        dp[i] = min(dp[i - 1] + 1, a);
    }

    cout << dp[n];

    return 0;
}