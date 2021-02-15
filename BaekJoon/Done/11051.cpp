
#include <iostream>

using namespace std;

int n, k;
int pascal[1001][1001];

int Pascal(int n, int k)
{
    if (n == k || k == 0)
        return 1;
    if (pascal[n][k] == 0)
    {
        pascal[n][k] = Pascal(n - 1, k - 1) % 10007 + Pascal(n - 1, k) % 10007;
    }
    return pascal[n][k];
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n >> k;
    cout << Pascal(n, k) % 10007;
}