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

// Runtime  : 606ms     5.13%
// Memory   : 152.6MB   5.54%

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> array;
        int answer = 0, lenth = 0;
        int cachedIndex = 0;

        for (int i = 0; i < s.length();)
        {
            auto iter = array.find(s[i]);
            if (iter == array.end())
            {
                lenth++;
                if (lenth == 2)
                {
                    cachedIndex = i;
                }
            }
            else
            {
                answer = max(answer, lenth);
                lenth = 1;
                array.clear();
                i = cachedIndex++;
            }
            array.insert(s[i]);
            i++;
        }

        answer = max(answer, lenth);
        return answer;
    }
};