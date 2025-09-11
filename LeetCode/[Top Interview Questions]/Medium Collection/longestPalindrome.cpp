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

// Runtime  : 20ms     53.74%
// Memory   : 35.3MB   29.24%

class Solution
{
public:
    string longestPalindrome(string s)
    {
        string ans;

        for (int centerIndex = 0; centerIndex < s.size(); ++centerIndex)
        {
            int L = centerIndex, R = centerIndex;
            while (L - 1 >= 0 && s[centerIndex] == s[L - 1])
            {
                L--;
            }

            while (R + 1 <= s.size() && s[centerIndex] == s[R + 1])
            {
                R++;
            }

            while (L - 1 >= 0 && R + 1 <= s.size() && s[L - 1] == s[R + 1])
            {
                L--;
                R++;
            }

            int len = R - L + 1;

            ans = ans.size() > len ? ans : s.substr(L, R - L + 1);
        }
        return ans;
    }
};