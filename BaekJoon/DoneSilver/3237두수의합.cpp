
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, goal, ans = 0, startPoint = 0, endPoint = 0;
int arr[100001];

void Process()
{
    endPoint = n - 1;
    while (true)
    {
        if (endPoint == startPoint)
            break;
        if (arr[startPoint] + arr[endPoint] == goal)
            ans++;

        if (arr[startPoint] + arr[endPoint] <= goal)
            startPoint++;
        else if (arr[startPoint] + arr[endPoint] > goal)
            endPoint--;
    }
    cout << ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> goal;
    sort(arr, arr + n);
    Process();
}