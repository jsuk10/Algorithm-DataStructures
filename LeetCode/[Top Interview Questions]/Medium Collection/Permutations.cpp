#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Runtime  : 0ms       100.00%
// Memory   : 10.6MB   69.0%

class Solution {
    void Backtraking(vector<vector<int>>& ans, vector<int>& target, const vector<int>& nums, vector<int>& bitMask)
    {
        if (target.size() == nums.size())
        {
            ans.push_back(target);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (bitMask[i] != 0)
                continue;
            target.push_back(nums[i]);
            bitMask[i] = 1;

            Backtraking(ans, target, nums, bitMask);

            bitMask[i] = 0;
            target.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        // 사용한 원소 체크.
        vector<int> bitMask(6, 0);
        vector<int> value;
        Backtraking(ans, value, nums, bitMask);
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v = { 1 };
    auto b = s.permute(v);

    for (auto a : b)
    {
        for (auto c : a)
        {
            cout << c << ", ";
        }
        cout << endl;
    }
}
