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

// Runtime  : 0ms       100.00%
// Memory   : 8.6MB     82.03%

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        for (int i = 0; i < haystack.length(); i++)
        {
            for (auto j = 0; j < needle.length(); j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    break;
                }
                if (j == needle.length() - 1)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};