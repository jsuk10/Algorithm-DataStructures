#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstring>
#include <deque>
#include <stack>
#include <string>
#include <string_view>
#include <utility>
#include <queue>
#include <cmath>

using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int index = 0;
        for (int i = 0; i < t.size(); i++)
        {
            if (s[index] == t[i])
            {
                index++;
            }
        }
        return index == s.size();
    }
};

int main()
{
    // vector<int> v = {1, 2, 5};
    vector<int> v = {7, 1, 5, 3, 6, 4};
    string a = "abc";
    string b = "ahbgdc";

    auto c = Solution().isSubsequence(a, b);

    // for (auto b : c)
    // {
    //     cout << b << endl;
    // }

    cout << c << endl;
    return 0;
}