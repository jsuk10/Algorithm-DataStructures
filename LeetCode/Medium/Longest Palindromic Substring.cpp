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
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> ans;
        for (auto num : nums)
        {
            auto a = lower_bound(ans.begin(), ans.end(), num);
            if (a == ans.end())
            {
                ans.push_back(num);
            }
            else
            {
                *a = num;
            }
        }

        return ans.size();
    }
};
int main()
{
    // vector<int> v = {1, 2, 5};
    vector<int> v = {10, 9, 2, 5, 3, 7, 101, 18};
    int c = Solution().lengthOfLIS(v);
    cout << c << endl;
    return 0;
}