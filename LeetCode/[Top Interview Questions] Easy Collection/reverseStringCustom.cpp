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
    void reverseString(vector<char>& s) {
        auto first = s.begin();
        auto last = s.end();
        while (first != last && first != --last)
        {
            auto temp = *first;
            *first = *last;
            *last = temp;
            first++;
        }
    }
};