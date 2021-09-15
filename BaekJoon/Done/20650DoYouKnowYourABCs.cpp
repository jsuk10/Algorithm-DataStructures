
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[7];
int ans[3] = {0};

int main()
{
    freopen("input.txt", "r", stdin);
    for(int i = 0 ; i < 7; i++){
        cin >> arr[i];
    }
    sort(arr, arr+7);
    // a = (a+b+c) - (b+c)
    ans[0] = arr[6] - arr[5];
    // b = (a+b+c) - (a+c)
    ans[1] = arr[6] - arr[4];
    // (a+b+c) - a - b
    ans[2] = arr[6] - ans[0] - ans[1];
    for(int i = 0 ; i < 3; i++)
        cout << ans[i] <<" ";
}

