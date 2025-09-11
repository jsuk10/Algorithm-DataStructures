#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int count = 0;
        // O(n^2) = loop O(n) * erase O(n)
        for (auto i = nums.begin(); i != nums.end(); )
        {
            if (*i == 0)
            {
                // O(n)
                nums.erase(i);
                count++;
            }
            else
            {
                i++;
            }
        }


        for (int i = 0; i < count; i++)
        {
            nums.push_back(0);
        }
    }
};