#include <iostream>
using namespace std;

int cal(int num) {
    if (num <= 1)
        return 1;
    else
        return cal(num - 1) * num;
}

int main() {
    int num;
    cin >> num;
    cout << cal(num) << "\n";
}