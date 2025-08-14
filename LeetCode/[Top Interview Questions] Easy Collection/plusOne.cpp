#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool laset = false;
        reverse(digits.begin(), digits.end());

        for (auto a = digits.begin(); a < digits.end(); a++)
        {
            int& value = (*a);
            value++;

            if (value < 10) break;
            else
            {
                value -= 10;
                if (a + 1 == digits.end())
                {
                    digits.push_back(1);
                    break;
                }
            }
        }

        reverse(digits.begin(), digits.end());
        return digits;
    }
};