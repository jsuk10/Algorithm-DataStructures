#include <iostream>
using namespace std;

int cal(int num) {
    if (num == 0)
        return 1;
    else
        return cal(num - 1) * 2;
}

void Process(int num, int from, int to, int by) {
    if (num == 0)
        return;
    Process(num - 1, from , by, to);
    cout << from << " " << to << "\n";
    Process(num - 1, by, to, from);
}

int main() {
    int num;
    cin >> num;
    cout << cal(num)-1 << "\n";
    Process(num, 1, 3, 2);
}