#include <iostream>
#include <vector>

using namespace std;

vector<int> numVector;
int maxNum = 2666800;

bool jagu(int num)
{
    if (num % 1000 == 666)
    {
        return true;
    }
    else if (num >= 1000)
        return jagu(num / 10);
    else
    {
        return false;
    }
}

void Search()
{
    for (int i = 666; i < maxNum; i++)
    {
        if (jagu(i) == true)
        {
            numVector.push_back(i);
        }
    }
}

int main()
{
    Search();
    int N = 0;
    cin >> N;
    cout << numVector[N - 1];
}