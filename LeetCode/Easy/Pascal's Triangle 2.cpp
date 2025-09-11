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
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> ans;
        for (int i = 0; i <= rowIndex; i++)
        {
            vector<int> v;
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || j == i)
                {
                    v.push_back(1);
                    continue;
                }
                int item = ans[i - 1][j - 1] + ans[i - 1][j];
                v.push_back(item);
            }
            ans.push_back(v);
        }
        return ans.back();
    }
};

int main()
{
    // vector<int> v = {1, 2, 5};
    vector<int> c = Solution().getRow(3);
    for (auto b : c)
    {
        cout << b << " ";
        cout << endl;
    }

    return 0;
}