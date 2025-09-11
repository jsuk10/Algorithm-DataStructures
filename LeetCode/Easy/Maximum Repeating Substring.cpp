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
    int maxRepeating(string sequence, string word)
    {
        vector<int> dp(sequence.size() + 1, 0);
        int ans = 0;
        for (int i = word.size(); i <= sequence.size(); i++)
        {
            if (sequence.substr(i - word.size(), word.size()) == word)
            {
                dp[i] = dp[i - word.size()] + 1;
                ans = max(dp[i], ans);
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> v = {10, 15, 20};
    // vector<string> v = {"a", "bb", "acd", "ace"};

    auto c = Solution().maxRepeating("aaabaaaabaaabaaaabaaaabaaaabaaaaba", "aaaba");

    // for (auto b : c)
    // {
    //     cout << b << endl;
    // }

    cout << c << endl;
    return 0;
}