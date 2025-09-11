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
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minvalue = prices[0];
        int maxvalue = prices[0];
        vector<int> dp(prices.size() + 1, 0);
        dp[0] = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (minvalue > prices[i])
            {
                minvalue = prices[i];
                maxvalue = 0;
            }
            else
            {
                maxvalue = max(maxvalue, prices[i]);
            }

            dp[i + 1] = maxvalue - minvalue >= dp[i] ? maxvalue - minvalue : dp[i];
        }
        return dp[prices.size()];
    }
};

int main()
{
    // vector<int> v = {1, 2, 5};
    vector<int> v = {7, 1, 5, 3, 6, 4};
    int c = Solution().maxProfit(v);
    cout << c;

    return 0;
}