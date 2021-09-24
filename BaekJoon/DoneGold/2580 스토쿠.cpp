
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int arr[9][9];
int arrY[9][10];
int arrX[9][10];
int arrBox[9][10];
bool isFind = false;

void PrintArray()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
}

void DFS(int depth)
{
    if (depth == 81)
    {
        PrintArray();
        isFind = true;
    }
    int y = depth / 9;
    int x = depth % 9;
    //아니면 뎁스 높여서 함 더
    if (arr[y][x] != 0)
        DFS(depth + 1);
    else
    {
        //백트레킹
        for (int i = 1; i <= 9; i++)
        {
            if (arrY[x][i] == 0 && arrX[y][i] == 0 && arrBox[((y / 3) * 3 + x / 3)][i] == 0)
            {
                arr[y][x] = i;
                arrY[x][i] = 1;
                arrX[y][i] = 1;
                arrBox[((y / 3) * 3 + x / 3)][i] = 1;
                DFS(depth + 1);
                if (isFind == true)
                    return;
                arr[y][x] = 0;
                arrY[x][i] = 0;
                arrX[y][i] = 0;
                arrBox[((y / 3) * 3 + x / 3)][i] = 0;
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            cin >> arr[y][x];
            arrY[x][arr[y][x]] = 1;
            arrX[y][arr[y][x]] = 1;
            arrBox[((y / 3) * 3 + x / 3)][arr[y][x]] = 1;
        }
    }
    DFS(0);
}