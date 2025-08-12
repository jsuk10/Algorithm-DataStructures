#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> uniqueElements;
        
        for (auto i = nums.begin() ; i < nums.end() ; i++)
        {
            uniqueElements.insert(*i);
        }
        nums = vector<int>(uniqueElements.begin(), uniqueElements.end());
        return uniqueElements.size();
    }
};