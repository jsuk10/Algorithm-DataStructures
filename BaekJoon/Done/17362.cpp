#include <iostream>

using namespace std;

int arr[8] = {2, 1, 2, 3, 4, 5, 4, 3};

int main()
{

    int num;
    cin >> num;
    cout << arr[num % 8];
}