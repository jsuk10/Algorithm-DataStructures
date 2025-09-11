#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstring>
#include <deque>
#include <stack>
#include <string>
#include <string_view>
#include <utility>
#include <queue>
#include <cmath>

using namespace std;

class Solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n <= 2)
            return 1;

        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        return dp[n];
    }
};

int main()
{
    vector<int> v = {10, 15, 20};
    // vector<string> v = {"a", "bb", "acd", "ace"};

    auto c = Solution().tribonacci(25);

    // for (auto b : c)
    // {
    //     cout << b << endl;
    // }

    cout << c << endl;
    return 0;
}