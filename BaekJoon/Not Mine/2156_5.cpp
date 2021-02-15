#include <iostream>
#include <algorithm>

using namespace std;

int caseNum;
int numArr[10001], dp[10001];

int Check(int a, int b, int c)
{
    int arr[] = {a, b, c};
    sort(arr, arr + 3);
    return arr[2];
}

int main()
{
    cin >> caseNum;
    for (int i = 0; i < caseNum; i++)
    {
        cin >> numArr[i];
    }
    dp[0] = numArr[0];
    if (caseNum >= 2)
        dp[1] = numArr[0] + numArr[1];
    if (caseNum >= 3)
        for (int i = 2; i < caseNum; i++)
        {
            dp[i] = Check(dp[i - 1], dp[i - 2] + numArr[i], dp[i - 3] + numArr[i - 1] + numArr[i]);
        }
    cout << dp[caseNum - 1];
}