#include <iostream>
#include <algorithm>

using namespace std;

int *arr;
int n;

int main()
{


    cin >> n;
    arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(&arr[0], &arr[n]);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << '\n';
    }
}