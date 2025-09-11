#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> answer;

        // O(n^2) = loop O(n) * find O(n)
        for (auto index = 0; index < nums.size(); index++)
        {
            auto num = nums[index];
            auto a = find(nums.begin() + index + 1, nums.end(), target - num);
            if (a != nums.end())
            {
                int index2 = distance(nums.begin(), a);

                return vector<int>{index, index2};
            }
        }
        return vector<int>();
    }
};