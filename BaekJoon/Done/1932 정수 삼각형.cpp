
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxNum = 501;

vector<vector<int>> dp(maxNum, vector<int>(501, 0));

int main()
{
    // freopen("input.txt", "r", stdin);

    int n, a;
    cin >> n;

    vector<vector<int>> array;
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        for (int j = 0; j <= i; j++)
        {
            cin >> a;
            v.push_back(a);
        }
        array.push_back(v);
    }

    dp[0][0] = array[0][0];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i - 1][0] + array[i][0];
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + array[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp[n - 1][i]);
    }

    cout << ans;

    return 0;
}