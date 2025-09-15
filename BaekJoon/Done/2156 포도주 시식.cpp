
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int MOD = 1000000000;

int main()
{
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    if (n < 1)
    {
        return v[n - 1];
    }

    vector<int> dp(n + 1, 0);

    dp[0] = 0;
    dp[1] = v[0];
    dp[2] = v[0] + v[1];
    for (int i = 3; i <= n; i++)
    {
        int c = max(dp[i - 1], dp[i - 2] + v[i - 1]);
        c = max(dp[i - 3] + v[i - 2] + v[i - 1], c);

        dp[i] = c;
    }

    cout << dp[n];
    return 0;
}