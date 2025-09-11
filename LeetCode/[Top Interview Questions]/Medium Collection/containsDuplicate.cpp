#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> numSet;
        for (int a : nums)
        {
            if (numSet.find(a) == numSet.end())
            {
                numSet.insert(a);
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};