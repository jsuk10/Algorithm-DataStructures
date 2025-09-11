
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fibo(int num)
{
    if (num <= 2)
        return 1;

    vector<int> dp(num + 1, 0);

    dp[1] = 1;
    dp[2] = 1;

    for (int i = 2; i <= num; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[num];
}

int main()
{
    // freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    cout << fibo(n) << " " << n - 2 << endl;

    return 0;
}