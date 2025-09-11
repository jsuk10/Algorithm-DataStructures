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
    bool isPalindrome(string s) {

        for (auto a = s.begin() ; a != s.end() ;)
        {
            if (*a <= 'Z' && *a >= 'A')
            {
                *a -= ('A' - 'a');
            }

            if ((*a >= 'a' && *a <= 'z') || (*a >= '0' && *a <= '9'))
            {
                a++;
            }
            else
            {
                a = s.erase(a);
            }
        }

        if (s.length() <= 0) return true;

        int index = 0;
        while (index < s.length() - 1 - index)
        {
            if (s[index] != s[s.length() - 1 - index]) return false;
            index++;
        }
        return true;
    }
};