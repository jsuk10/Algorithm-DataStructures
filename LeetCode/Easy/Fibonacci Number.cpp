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
    int fib(int n)
    {
        if (n == 0)
            return 0;
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main()
{
    // vector<int> v = {1, 2, 5};
    vector<string> v = {"a", "bb", "acd", "ace"};
    string a = "abcdea";

    auto c = Solution().fib(0);

    // for (auto b : c)
    // {
    //     cout << b << endl;
    // }

    cout << c << endl;
    return 0;
}