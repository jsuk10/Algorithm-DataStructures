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
    vector<int> countBits(int n)
    {
        vector<int> dp(n + 1, 0);

        int maxcount = 1;
        int count = 0;
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i == maxcount)
            {
                maxcount *= 2;
                count = 0;
            }
            dp[i] = dp[count] + 1;
            count++;
        }

        return dp;
    }
};

int main()
{
    // vector<int> v = {1, 2, 5};
    vector<int> v = {7, 1, 5, 3, 6, 4};
    auto c = Solution().countBits(10);
    for (auto b : c)
    {
        cout << b << endl;
    }

    // cout << c << endl;
    return 0;
}