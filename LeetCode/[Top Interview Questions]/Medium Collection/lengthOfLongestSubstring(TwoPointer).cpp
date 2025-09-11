#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstring>

using namespace std;

// Runtime  : 19ms      30.52%
// Memory   : 14.3MB    31.17%

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> seen;
        int ans = 0, length = 0;
        int L = 0;

        for (int R = 0; R < s.size(); ++R)
        {
            while (seen.count(s[R]))
            {
                seen.erase(s[L++]);
                length--;
            }
            seen.insert(s[R]);
            ans = max(ans, length + 1);
            length++;
        }
        return ans;
    }
};