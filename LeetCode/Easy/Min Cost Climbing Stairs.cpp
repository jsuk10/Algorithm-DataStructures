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
    int minCostClimbingStairs(vector<int> &cost)
    {
        vector<int> dp(cost.size() + 1, INT_MAX);
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= cost.size(); i++)
        {
            dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
        }

        return dp[cost.size()];
    }
};

int main()
{
    vector<int> v = {10, 15, 20};
    // vector<string> v = {"a", "bb", "acd", "ace"};

    auto c = Solution().minCostClimbingStairs(v);

    // for (auto b : c)
    // {
    //     cout << b << endl;
    // }

    cout << c << endl;
    return 0;
}