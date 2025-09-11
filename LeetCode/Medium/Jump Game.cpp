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
    bool canJump(vector<int> &nums)
    {
        int maxRich = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > maxRich)
                return false;
            maxRich = max(maxRich, i + nums[i]);
        }
        return true;
    }
};