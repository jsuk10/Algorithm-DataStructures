#include <iostream>
#include <algorithm>

using namespace std;

int arr[3];

void process() {
    cin >> arr[0] >> arr[1] >> arr[2];
    if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
        return;

    sort(arr, arr+3);
    if (arr[2] * arr[2] == arr[0] * arr[0] + arr[1] * arr[1])
        cout << "right"<< endl;
    else
        cout << "wrong" << endl;
    process();
}

int main()
{
    process();
}