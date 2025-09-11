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
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, INT_MAX - 1);
        dp[0] = 0;
        for (int i = 0; i <= amount; i++)
        {
            for (auto coin : coins)
            {
                if (i - coin < 0)
                    continue;
                dp[i] = min(dp[i - coin] + 1, dp[i]);
            }
        }
        return dp[amount] == INT_MAX - 1 ? -1 : dp[amount];
    }
};

int main()
{
    // vector<int> v = {1, 2, 5};
    vector<int> v = {1, 2, 5};
    int c = Solution().coinChange(v, 11);
    cout << c << endl;
    return 0;
}