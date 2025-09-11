#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        vector<vector<int>> num;
        int ans = 0;
        for (int i = 1;  i < prices.size() ; i++)
        {
            ans += max(prices[i] - prices[i-1], 0);
        }
        return ans;
    }
};