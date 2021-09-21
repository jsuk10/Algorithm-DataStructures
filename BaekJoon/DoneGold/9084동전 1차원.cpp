
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int caseNum;

void Process()
{
    int coinCount, goal, temp;
    cin >> coinCount;
    vector<int> items;

    for (int i = 0; i < coinCount; i++)
    {
        cin >> temp;
        items.push_back(temp);
    }

    cin >> goal;

    int dp[10001] = {0};

    for (int j = items[0]; j <= goal; j = j + items[0])
    {
        dp[j]++;
    }

    //i 가 쓸수있는 동전 수 j가 금액
    for (int i = 1; i < items.size(); i++)
    {
        if (items[i] > goal)
            break;
        for (int j = 1; j <= goal; j++)
        {
            // //같을 경우
            if (j == items[i])
                dp[items[i]] = dp[items[i]] + 1;
            else if (j > items[i])
            {
                dp[j] = dp[j] + dp[j - items[i]];
                // cout << j << " " << j - items[i] << "\n";
            }
        }
    }

    cout << dp[goal] << "\n";
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> caseNum;
    for (int i = 0; i < caseNum; i++)
        Process();
}