#include <iostream>

using namespace std;

//일단 전부 계산하는거 만들고
//이후에 가지치기 해보자

int num[12];
int op[4];
int numSize;
int maxNum = -1000000000, minNum = 1000000000;

int Calculation(int value, int index, int ops)
{
    switch (ops)
    {
    case 0:
        return value + num[index];
        break;
    case 1:
        return value - num[index];
        break;
    case 2:
        return value * num[index];
        break;
    case 3:
        return value / num[index];
        break;

    default:
        break;
    }
}

void process(int index, int value)
{
    int tempValue = value;
    if (index == numSize)
    {
        minNum = (minNum > value ? value : minNum);
        maxNum = (maxNum < value ? value : maxNum);
        return;
    }
    for (int j = 0; j < 4; j++)
    {
        if (op[j] == 0)
            continue;
        op[j]--;
        tempValue = Calculation(tempValue, index, j);
        index++;
        process(index, tempValue);
        op[j]++;
        index--;
        tempValue = value;
    }
}

int main()
{
    cin >> numSize;
    for (int i = 0; i < numSize; i++)
        cin >> num[i];
    for (int i = 0; i < 4; i++)
        cin >> op[i];

    process(1, num[0]);

    cout << maxNum << "\n"
         << minNum;
}