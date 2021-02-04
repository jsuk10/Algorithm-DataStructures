#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Atm
{
public:
    int index;
    int time;

    Atm(int index, int time)
    {
        this->index = index;
        this->time = time;
    }
};

bool Compare(Atm a, Atm b)
{
    return a.time < b.time;
}

int main()
{
    freopen("input.txt", "r", stdin);
    vector<Atm> v;
    vector<int> timeSum;
    int tempTime, sum = 0, caseNum;
    cin >> caseNum;
    for (int i = 0; i < caseNum; i++)
    {
        cin >> tempTime;
        Atm tempAtm(i + 1, tempTime);
        v.push_back(tempAtm);
    }

    sort(v.begin(), v.end(), Compare);

    timeSum.push_back(v[0].time);
    sum += timeSum[0];
    for (int i = 1; i < caseNum; i++)
    {
        timeSum.push_back(timeSum[i - 1] + v[i].time);
        sum += timeSum[i];
    }
    cout << sum;
}
