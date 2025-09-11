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
    int climbStairs(int n)
    {
        vector<int> dp(n, 0);
        dp[0] = 1;
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
    vector<int> v = {10, 9, 2, 5, 3, 7, 101, 18};
    int c = Solution().climbStairs(10);
    cout << c << endl;
    return 0;
}