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
    vector<string> getLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        vector<string> ans;
        int pre = -1;
        for (int i = 0; i < groups.size(); i++)
        {
            if (pre != groups[i])
            {
                ans.push_back(words[i]);
                pre = groups[i];
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> v = {0, 0, 1};
    vector<string> v2 = {"e", "a", "b"};

    auto c = Solution().getLongestSubsequence(v2, v);

    for (auto b : c)
    {
        cout << b << endl;
    }

    // cout << c << endl;
    return 0;
}