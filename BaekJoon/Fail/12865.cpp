#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Stuff
{
public:
    int weight;
    int value;
    Stuff(int w, int v)
    {
        this->weight = w;
        this->value = v;
    }
};

bool Compare(Stuff a, Stuff b)
{
    return a.weight > b.weight;
}

int maxWeight, caseNum;
vector<Stuff> v;

int main()
{
    freopen("input.txt", "r", stdin);
    int tempWeight, tempValue;
    cin >> caseNum >> maxWeight;
    for (int i = 0; i < caseNum; i++)
    {
        cin >> tempWeight >> tempValue;
        Stuff tempStuff(tempWeight, tempValue);
        v.push_back(tempStuff);
    }
    vector<int> dp(maxWeight + 1, 0);
    sort(v.begin(), v.end(), Compare);

    int value;
    for (int i = 0; i < caseNum; i++)
    {
        for (int j = v[i].weight; j <= maxWeight; j++)
        {
            //지금 기록된 dp와 새로 무게를 넣는 것과 비교하여 높은값 삽입
            dp[j] = max(dp[j], dp[j - v[i].weight] + v[i].value);
        }

        for (int i = 0; i <= maxWeight; i++)
        {
            cout << dp[i] << " ";
        }
        cout << "\n";
    }
    cout << dp.back();
}