
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxNum = 1001;

vector<vector<int>> dp(maxNum, vector<int>(3, 0));

int main()
{
    // freopen("input.txt", "r", stdin);

    int n, a;
    cin >> n;

    vector<vector<int>> array;
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        for (int j = 0; j < 3; j++)
        {
            cin >> a;
            v.push_back(a);
        }
        array.push_back(v);
    }

    int ans = 0;
    for (int j = 0; j < 3; j++)
    {
        dp[0][j] = array[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + array[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + array[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + array[i][2];
    }
    ans = min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);

    cout << ans;

    return 0;
}