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

// Runtime  : 6ms       15.77%
// Memory   : 115.5MB   98.08%

class Solution
{
public:
    bool increasingTriplet(vector<int> &num)
    {
        vector<int> tails;
        for (int x : num)
        {
            auto it = lower_bound(tails.begin(), tails.end(), x);
            if (it == tails.end())
            {
                if (tails.size() >= 2)
                    return true;
                tails.push_back(x);
            }
            else
            {
                *it = x;
            }
        }
        return false;
    }
};