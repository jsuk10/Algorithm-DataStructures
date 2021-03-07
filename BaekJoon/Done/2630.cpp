
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[129][129], n;
int answer[2];

void quadTree(int X, int Y, int size)
{
    if (size == 0)
        return;

    int firstData = arr[Y][X];
    bool isCombine = true;

    for (int i = Y; i < Y + size; i++)
    {
        for (int j = X; j < X + size; j++)
        {
            if (firstData != arr[i][j])
            {
                isCombine = false;
                break;
            }
        }
        if (isCombine == false)
            break;
    }

    //병합 가능 ^^
    if (isCombine)
    {
        answer[firstData]++;
        return;
    }

    //응 앙대 분활해~
    int halfSize = size / 2;
    quadTree(X, Y, halfSize);
    quadTree(X + halfSize, Y, halfSize);
    quadTree(X, Y + halfSize, halfSize);
    quadTree(X + halfSize, Y + halfSize, halfSize);
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    quadTree(0, 0, n);
    cout << answer[0] << " " << answer[1];
}