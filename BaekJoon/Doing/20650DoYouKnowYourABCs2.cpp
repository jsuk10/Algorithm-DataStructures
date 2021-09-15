#include <iostream>
#include <algorithm>

using namespace std;

int arr[7];

int main()
{
    for(int i = 0 ; i < 7; i++){
        cin >> arr[i];
    }
    sort(arr,arr+7);
    cout << arr[0] <<"\n"<< arr[1] << "\n"<< arr[6] - arr[0] -arr[1];
}

