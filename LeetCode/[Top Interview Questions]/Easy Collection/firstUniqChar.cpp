#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26] = {0,};
        
        for (auto a : s)
        {
            arr[a - 'a']++;
        }

        for (auto i = 0 ; i < s.length(); i++)
        {
            if (arr[s[i] - 'a'] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};