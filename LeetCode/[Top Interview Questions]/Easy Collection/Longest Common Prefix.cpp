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
// Memory   : 11.8MB    66.77%

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string answer = "";
        for (int i = 0; i < strs[0].size(); i++)
        {
            for (int j = 1; j < strs.size(); j++)
            {
                if (strs[j][i] != strs[0][i])
                {
                    return answer;
                }
            }
            answer += strs[0][i];
        }
        return answer;
    }
};