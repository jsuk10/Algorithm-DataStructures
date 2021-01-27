#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int caseNum;

class point
{
public:
    int x;
    int y;

    point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

bool comp(point a, point b)
{
    if (a.x == b.x)
        return a.y < b.y;
    else
    {
        return a.x < b.x;
    }
}

int main()
{

    cin >> caseNum;
    int tempX, tempY;
    vector<point> pv;
    for (int i = 0; i < caseNum; i++)
    {
        cin >> tempX >> tempY;
        point p(tempX, tempY);
        pv.push_back(p);
    }
    sort(pv.begin(), pv.end(), comp);

    for (int i = 0; i < caseNum; i++)
    {
        cout << pv[i].x << " " << pv[i].y << "\n";
    }
}