#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item
{
    int w;
    int p;
    Item(int w, int p) : w(w), p(p){};
};

bool Sort(Item a, Item b)
{
    return a.w > b.w;
}

int caseNum, maxW, tempW, tempP, dp[101][100001];
vector<Item> v;

void Process()
{
    //i = 선택된 아이템, j = 무게
    for (int i = 1; i <= caseNum; i++)
    {
        for (int j = v[i - 1].w; j <= maxW; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1].w] + v[i - 1].p);
        }
    }
    cout << dp[caseNum][maxW];
}

int main()
{
    cin >> caseNum >> maxW;
    for (int i = 0; i < caseNum; i++)
    {
        cin >> tempW >> tempP;
        v.push_back(Item(tempW, tempP));
        // dp[0][tempW] = tempP;
    }
    sort(v.begin(), v.end(), Sort);
    Process();
}