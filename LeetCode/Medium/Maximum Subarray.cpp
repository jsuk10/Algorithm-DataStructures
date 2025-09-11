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
    int maxSubArrayoptimize(vector<int> &nums)
    {
        int ans = nums[0];
        int prev = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            prev = max(nums[i], prev + nums[i]);
            ans = max(ans, prev);
        }

        return ans;
    }

    int maxSubArrayWithDP(vector<int> &nums)
    {
        vector<int> dp(nums.size() + 1, 0);
        dp[0] = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            ans = max(dp[i], ans);
        }

        return ans;
    }
};

int main()
{
    vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // vector<string> v2 = {"bab", "dab", "cab"};

    auto c = Solution().maxSubArray(v);

    // for (auto b : c)
    // {
    //     cout << b << endl;
    // }

    cout << c << endl;
    return 0;
}