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
    int reverse(int x) {
        int answer = 0;
        while (x != 0)
        {
            if (answer > INT_MAX / 10) return 0 ;
            if (answer < INT_MIN / 10) return 0 ;

            answer = answer * 10 + x % 10;
            x /= 10;
        }

        return answer;
    }
};