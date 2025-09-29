#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Runtime  : 0ms       100%
// Memory   : 9.3MB     56.92%

class Solution {
    unordered_map<char, vector<string>> map;
public:
    Solution()
    {
        map['0'] = { "" };
        map['1'] = { "" };
        map['2'] = { "a", "b", "c" };
        map['3'] = { "d", "e", "f" };
        map['4'] = { "g", "h", "i" };
        map['5'] = { "j", "k", "l" };
        map['6'] = { "m", "n", "o" };
        map['7'] = { "p", "q", "r", "s" };
        map['8'] = { "t", "u", "v" };
        map['9'] = { "w", "x", "y", "z" };
    }

    // 초기 솔루션
    vector<string> insertmap2(string target, char digits)
    {
        vector<string> returnValue;
        for (string a : map[digits])
        {
            returnValue.push_back(target + a);
        }
        return returnValue;
    }

    vector<string> letterCombinations2(string digits)
    {
        vector<string> ans = insertmap2("", digits[0]);
        for (int i = 1; i < digits.length(); i++)
        {
            vector<string> tempans;
            for (auto a : ans)
            {
                vector<string> temp = insertmap2(a, digits[i]);
                tempans.insert(tempans.end(), temp.begin(), temp.end());
            }
            ans = tempans;
        }
        return ans;
    }

    // insertmap2에서 필요없는 복사가 이루어져서 최적화함.
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty()) return {};

        vector<string> ans = map[digits[0]];

        for (int i = 1; i < digits.length(); i++)
        {
            vector<string> tempans;
            for (auto& prefix : ans)
            {
                for (auto& letter : map[digits[i]])
                {
                    tempans.push_back(prefix + letter);
                }
            }

            // 이동 연산자로 복사 비용 최소화
            ans = move(tempans);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    auto b = s.letterCombinations2("23");

    for (auto a : b)
    {
        cout << a << endl;
    }
}
