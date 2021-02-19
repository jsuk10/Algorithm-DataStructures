
#include <iostream>
using namespace std;

int dp[21][21][21];
int dpArr[21][21][21];

int Process(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }
    if (a > 20 || b > 20 || c > 20)
        return Process(20, 20, 20);
    if (dpArr[a][b][c] == 1)
    {
        return dp[a][b][c];
    }
    else
    {
        if (a < b && b < c)
        {
            dp[a][b][c] = Process(a, b, c - 1) + Process(a, b - 1, c - 1) - Process(a, b - 1, c);
            dpArr[a][b][c] = 1;
            return dp[a][b][c];
        }
        else
        {
            dp[a][b][c] = Process(a - 1, b, c) + Process(a - 1, b - 1, c) + Process(a - 1, b, c - 1) - Process(a - 1, b - 1, c - 1);
            dpArr[a][b][c] = 1;
            return dp[a][b][c];
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int a, b, c;
    while (true)
    {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
        {
            break;
        }
        cout << "W(" << a << ", " << b << ", " << c << ") = " << Process(a, b, c) << "\n";
    }
}