
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxNum = 501;

vector<int> dp(maxNum, 0);

int main()
{
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    vector<int> array;
    array.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        array.push_back(a);
    }

    dp[1] = array[1];
    dp[2] = array[1] + array[2];
    for (int i = 3; i <= n; i++)
    {
        dp[i] = max(dp[i - 2], array[i - 1] + dp[i - 3]) + array[i];
    }

    cout << dp[n];

    return 0;
}