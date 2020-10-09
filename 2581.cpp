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

void InputNum(int start, int Last)
{
    if (start < 2)
        start = 2;

    for (int k = start; k <= Last; k++)
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
