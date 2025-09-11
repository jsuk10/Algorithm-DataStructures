#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int swap = 0;
        
        // O(n)
        for (auto index = 0 ; index < nums.size(); index++)
        {
            if(nums[index] == 0)
            {
                swap++;
            }
            else if (swap > 0)
            {
                nums[index - swap] = nums[index];
                nums[index] = 0;
            }
        }
    }
};