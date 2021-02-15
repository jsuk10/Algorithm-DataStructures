#include <iostream>

using namespace std;

int maxSum, caseNum;
int numArr[10001], checkArr[10001];

void Check(int index, int count, int sum)
{
    //실패임
    if (index > caseNum)
        return;
    if (count <= 3)
    {
        if (checkArr[index - 1] && checkArr[index - 2])
            return;
        else
        {
            int tempnum = sum + numArr[index];
            maxSum = (maxSum < tempnum) ? sum + numArr[index] : maxSum;
            return;
        }
    }

    for (int i = index + 1; i < caseNum; i++)
    {
        checkArr[i] = 1;
        Check(i, count + 1, sum + numArr[i]);
        checkArr[i] = 0;
    }
}

int main()
{
    cin >> caseNum;
    for (int i = 0; i < caseNum; i++)
    {
        cin >> numArr[i];
    }
    for (int i = 0; i < caseNum - 2; i++)
    {
        checkArr[i] = 1;
        Check(i, 1, numArr[i]);
        checkArr[i] = 0;
    }
    cout << maxSum;
}