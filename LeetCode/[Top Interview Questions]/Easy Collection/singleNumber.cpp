#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> set;

        for (int a : nums)
        {
            if (set.find(a) == set.end())
            {
                set.insert(a);
            }
            else
            {
                set.erase(a);
            }
        }

        return *set.begin(); 
    }
};