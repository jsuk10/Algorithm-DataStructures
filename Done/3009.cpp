#include <iostream>
#include <vector>
using namespace std;

struct Point
{
    int x;
    int y;
};

struct Point p[4];

void Process()
{
    vector<int> vectorX1, vectorX2, vectorY1, vectorY2;
    vectorX1.push_back(p[0].x);
    vectorY1.push_back(p[0].y);

    for (int i = 1; i < 3; i++)
    {
        if (p[0].x == p[i].x)
            vectorX1.push_back(p[i].x);
        else
        {
            vectorX2.push_back(p[i].x);
        }
        if (p[0].y == p[i].y)
            vectorY1.push_back(p[i].y);
        else
        {
            vectorY2.push_back(p[i].y);
        }
    }

    if (vectorX1.size() == 1)
    {
        p[3].x = vectorX1[0];
    }
    else
    {
        p[3].x = vectorX2[0];
    }
    if (vectorY1.size() == 1)
    {
        p[3].y = vectorY1[0];
    }
    else
    {
        p[3].y = vectorY2[0];
    }
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        cin >> p[i].x >> p[i].y;
    }
    Process();
    cout << p[3].x << " " << p[3].y;
}