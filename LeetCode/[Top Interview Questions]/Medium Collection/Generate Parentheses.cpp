#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Runtime  : 0ms       100%
// Memory   : 10.3MB   98.74%

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<vector<string>> dp(9, vector<string>());

        dp[0] = { "" };

        
        for (int i = 1; i <= n; i++)
        {
            // i = 괄호의 총 갯수
            // j = dp의 괄호수
            // n = i - j - 1 // j로 인해 들어가는 괄호수
            for (int j = 0; j < i; j++)
            {
                int target = i - j - 1;
                auto d1 = dp[j];
                auto d2 = dp[target];
                for (auto a : d1)
                {
                    for (auto b : d2)
                    {
                        dp[i].push_back("(" + a + ")" + b);
                    }
                }
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution s;
    auto b = s.generateParenthesis(10);

    for (auto a : b)
    {
        cout << a << endl;
    }
}
