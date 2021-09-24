#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, goal, ansStart = 0, ansEnd = 0, startPoint = 0, endPoint = 0, minValue;
int arr[100001];

void Process()
{
    endPoint = n - 1;
    minValue = abs(arr[startPoint] + arr[endPoint]);
    ansStart = startPoint;
    ansEnd = endPoint;
    while (endPoint > startPoint)
    {
        if (arr[startPoint] + arr[endPoint] == 0)
        {
            ansStart = startPoint;
            ansEnd = endPoint;
            break;
        }
        if (abs(arr[startPoint] + arr[endPoint]) < minValue)
        {
            ansStart = startPoint;
            ansEnd = endPoint;
            minValue = abs(arr[startPoint] + arr[endPoint]);
        }

        if (arr[startPoint] + arr[endPoint] > 0)
            endPoint--;
        else
            startPoint++;
    }
    cout << arr[ansStart] << " " << arr[ansEnd];
}

int main()
{
    freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    Process();
}