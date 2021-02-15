#include <iostream>

using namespace std;

int arr[10000];
int caseNum, maxSum;

void check(int index, int count, int sum, int numSize, int arrs[])
{
    if (count == 3)
    {
        return;
    }
    //index가 caseNum넘어가면 출력
    if (index >= caseNum)
    {
        if (numSize >= caseNum - (caseNum / 3))
        {
            maxSum = (maxSum < sum) ? sum : maxSum;
            /*for (int i = 0; i < caseNum; i++)
                cout << arrs[i] << " ";
            cout << "sum = " << sum << "\n";
        */
        }
        return;
    }

    //카운트가 2이면 선택하면 안됨.
    //선택한 경우
    arrs[index] = 1;
    sum += arr[index];
    check(index + 1, count + 1, sum, numSize + 1, arrs);

    //선택하지 않은 경우
    arrs[index] = 0;
    sum -= arr[index];
    check(index + 1, 0, sum, numSize, arrs);
}

int main()
{

    cin >> caseNum;
    int arrs[10000] = {
        0,
    };
    for (int i = 0; i < caseNum; i++)
    {
        cin >> arr[i];
    }
    check(0, 0, 0, 0, arrs);
    cout << maxSum;
}