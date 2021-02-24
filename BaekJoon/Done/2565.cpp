
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Line
{
public:
    int A;
    int B;
    Line(int a, int b)
    {
        this->A = a;
        this->B = b;
    }
};

bool CompareA(Line a, Line b)
{
    return a.A < b.A;
}
bool CompareB(Line a, Line b)
{
    return a.B < b.B;
}

int tempA, tempB, caseNum;
vector<Line> v;
vector<Line> dp;

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> caseNum;
    for (int i = 0; i < caseNum; i++)
    {
        cin >> tempA >> tempB;
        v.push_back(Line(tempA, tempB));
    }
    sort(v.begin(), v.end(), CompareA);
    dp.push_back(v[0]);
    for (int i = 1; i < caseNum; i++)
    {
        if (dp.back().B < v[i].B)
        {
            dp.push_back(v[i]);
        }
        else
        {
            vector<Line>::iterator it = lower_bound(dp.begin(), dp.end(), v[i], CompareB);
            *it = v[i];
        }
    }

    cout << caseNum - dp.size();
}