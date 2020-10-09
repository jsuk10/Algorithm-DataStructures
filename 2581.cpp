#include <iostream>

using namespace std;

int minNum, sumNum;

void CheckPrimNum(int num)
{
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return;
    }

    if (minNum == 0)
        minNum = num;
    sumNum += num;
    return;
}

int InputNum(int start, int last)
{
    for (int k = start; k < last; k++)
        CheckPrimNum(k);

    (minNum == 0) ? cout << -1 : cout << sumNum << endl
                                      << minNum << endl;
}

int main()
{
    int start, end;
    cin >> start >> end;
    InputNum(start, end);
}