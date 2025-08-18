#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;

        sort(nums.begin(), nums.end());

        auto first = nums.begin();
        while (first != nums.end())
        {
            // 이전값과 같을 경우 건너 뜀.
            if (first != nums.begin() && *first == *(first -1))
            {
                first++;
                continue;
            }

            auto second = first + 1;
            auto three = nums.end() - 1;
            while (second < three)
            {
                int sum = *first + *second + *three;
                if (sum > 0)
                {
                    three--;
                }
                else if (sum < 0)
                {
                    second++;
                }
                else if (sum == 0)
                {
                    answer.push_back({*first, *second, *three});
                    second++;
                    three--;
                    
                    while (second < three && *three == *(three + 1)) three--;
                    while (second < three && *second == *(second - 1)) second++;
                }
            }
            first++;
        }

        return answer;
    }

};