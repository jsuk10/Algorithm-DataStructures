#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int caseNum;

void Process()
{
    int coinCount, goal, temp, ans;
    cin >> coinCount;
    vector<int> items;

    for (int i = 0; i < coinCount; i++)
    {
        cin >> temp;
        items.push_back(temp);
    }

    cin >> goal;

    int dp[21][10001];
    for (int i = 0; i < items.size(); i++)
    {
        memset(dp[i], 0, sizeof(int) * (goal + 1));
    }

    for (int j = items[0]; j <= goal; j++)
    {
        if (items[0] > goal)
            break;
        if (j % items[0] == 0)
        {
            dp[0][j]++;
        }
    }

    //i 가 쓸수있는 동전 수 j가 금액
    for (int i = 1; i < items.size(); i++)
    {
        if (items[i] > goal)
            break;
        for (int j = 1; j <= goal; j++)
        {
            //이전거 그대로 가져옴
            if (j - items[i] < 0)
                dp[i][j] = dp[i - 1][j];
            else if (j - items[i] == 0)
                dp[i][items[i]] = dp[i - 1][items[i]] + 1;
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - items[i]];
            }
            ans = dp[i][j];
        }
    }

    // 틀린답
    // cout << dp[items.size() - 1][goal] << "\n";
    // why??

    //정답
    cout << ans << "\n";
}

int main()
{
    cin >> caseNum;
    for (int i = 0; i < caseNum; i++)
        Process();
}