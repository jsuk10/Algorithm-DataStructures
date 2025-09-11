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
// Memory   : 8.7MB     58.23%

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        return haystack.find(needle);
    }
};