#include <iostream>
#include <vector>
using namespace std;

void Process(int num, char from, char to, char by) {
    if (num == 0)
        return;
    Process(num - 1, from , by, to);
    cout << from << "에서" << to << "으로" << num << "번  \n";
    Process(num - 1, by, to, from);
}

int main() {
    int num;
    char A = 'S', B = 'D', C = 'T';
    cin >> num;
    Process(num, A,B,C);
}
