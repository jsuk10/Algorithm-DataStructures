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
    int myAtoi(string s) {
        int answer = 0;
        int isplus = -1;

        for (int index = 0; index < s.length(); index++)
        {
            if (s[index] == ' ' && isplus == -1)
                continue;

            if (isplus == -1 && (s[index] == '+' || s[index] == '-'))
            {
                isplus = s[index] == '+' ? 1 : 0;
                continue;
            }

            if (s[index] > '9' || s[index] < '0')
                break;

            if (isplus == -1) isplus = 1;
            // 오버플로 계산
            if (answer > INT_MAX / 10)
            {
                return isplus == 1 ? INT_MAX : INT_MIN;
            } 
            else if (answer == INT_MAX / 10)
            {
                if ((isplus == 1 && s[index] - '0' >= 7) ||
                    (isplus == 0 && s[index] - '0' >= 8))
                {
                    return isplus == 1 ? INT_MAX : INT_MIN;
                }
            }

            answer = answer * 10 + (s[index] - '0');
        }
        return isplus == 1 ? answer : -answer;
    }
};