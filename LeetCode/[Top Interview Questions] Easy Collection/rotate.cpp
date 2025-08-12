#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:

    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end());
        if (k > nums.size())
        {
            k %= nums.size();
        }
        nums.insert(nums.end(), nums.begin() , nums.begin() + k);
        nums.erase(nums.begin() , nums.begin() + k);
        reverse(nums.begin(), nums.end());
    }
};