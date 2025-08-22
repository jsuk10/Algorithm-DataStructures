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

// Runtime  : 3ms     97.90%
// Memory   : 9.3MB   82.01%

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int bestL = 0, bestLen = 0;

        for (int centerIndex = 0; centerIndex < s.size(); ++centerIndex)
        {
            int L = centerIndex, R = centerIndex;
            while (R + 1 < s.size() && s[R + 1] == s[centerIndex])
                R++;

            while (L - 1 >= 0 && R + 1 < s.size() && s[L - 1] == s[R + 1])
            {
                L--;
                R++;
            }

            if (R - L + 1 > bestLen)
            {
                bestLen = R - L + 1;
                bestL = L;
            }
        }
        return s.substr(bestL, bestLen);
    }
};