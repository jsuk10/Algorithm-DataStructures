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
    bool divisorGame(int n)
    {
        return n % 2;
    }
};

int main()
{
    vector<int> v = {10, 15, 20};
    // vector<string> v = {"a", "bb", "acd", "ace"};

    auto c = Solution().divisorGame(10);

    // for (auto b : c)
    // {
    //     cout << b << endl;
    // }

    cout << c << endl;
    return 0;
}