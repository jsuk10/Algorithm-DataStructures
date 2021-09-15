#include <iostream>
#include <vector>
#include <map>

using namespace std;

int arr[6][6];
//그냥 놓을 경우 최소값이 음수로 됨.
int answer = -999;

void Porcess(int i, int j)
{
    int temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1] + arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];
    answer = (temp > answer) ? temp : answer;
}
int main()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            Porcess(i, j);
        }
    }
    cout << answer;
}
