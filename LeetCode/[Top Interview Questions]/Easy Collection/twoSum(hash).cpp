#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, vector<int>> map;

        // O(n)
        for (int index= 0 ; index < nums.size() ;index++)
        {
            map[nums[index]].push_back(index);
        }

        // Average O(n) Worst-case{hash collision} O(n^2)
        for (int index= 0 ; index < nums.size() ;index++)
        {
            int searchNum = target - nums[index];
            if (map[searchNum].size() >= 1)
            {
                if (map[searchNum][0] != index)
                {
                    return vector<int>{index, map[searchNum][0]};
                }
                else if (map[searchNum].size() >= 2 )
                {
                    return vector<int>{index, map[searchNum][1]};
                }
            }
        }

        return vector<int>();
    }
};