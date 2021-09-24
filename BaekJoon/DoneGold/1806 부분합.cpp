
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int caseNum, goal, arr[100001], arr2[100001];

void Process()
{
    int startIndex = 0, endIndex = 1, ans = caseNum + 1;
    if (arr2[caseNum] < goal)
    {
        cout << 0;
        return;
    }

    while (startIndex < caseNum && endIndex < caseNum)
    {
        // start ~ end 의 합
        int sum = arr2[endIndex + 1] - arr2[startIndex];

        if (sum >= goal)
        {
            ans = min(ans, (endIndex + 1) - startIndex);
            startIndex++;
        }
        else
            endIndex++;
    }
    cout << ans;
}

int main()
{
    cin >> caseNum >> goal;
    cin >> arr[0];
    arr2[0] = 0;
    arr2[1] = arr[0];
    for (int i = 1; i < caseNum; i++)
    {
        cin >> arr[i];
        arr2[i + 1] = arr2[i] + arr[i];
    }

    Process();
}