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

using namespace std;

// Runtime  : 3ms      82.95%
// Memory   : 10.1MB   36.45%

class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
        {
            return "1";
        }
        string s = countAndSay(n - 1);
        string ans;
        for (int i = 0; i < s.length(); i++)
        {
            int cnt = 1;
            for (auto j = i + 1; j < s.length(); j++, i++, cnt++)
            {
                if (s[i] != s[j])
                    break;
            }
            ans += to_string(cnt) + s[i];
        }
        return ans;
    }
};