#include <iostream>

using namespace std;

int sum, maxSum, caseNum;
int sums[10000], numArr[10000];

int Big(int a, int b, int c)
{
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c)
        return b;
    else if (c >= a && c >= b)
        return c;
}

void check()
{
    for (int i = 1; i < caseNum; i++)
    {
    }
}

int main()
{
    cin >> caseNum;
    for (int i = 0; i < caseNum; i++)
    {
        cin >> numArr[i];
    }

    cout << maxSum;
}