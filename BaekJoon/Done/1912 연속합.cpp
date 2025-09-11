
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxNum = 100000;

vector<int> dp(maxNum + 1, 0);

int memo(vector<int> v)
{
    int ans = v[0];
    dp[0] = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        dp[i] = max(v[i], dp[i - 1] + v[i]);
        ans = max(dp[i], ans);
    }
    return ans;
}

int main()
{
    // freopen("input.txt", "r", stdin);

    int n, a;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }

    auto ans = memo(v);

    cout << ans;

    return 0;
}