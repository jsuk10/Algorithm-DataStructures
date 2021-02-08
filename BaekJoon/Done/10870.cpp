#include <iostream>
using namespace std;

int cal(int num)
{
    if (num == 0)
        return 0;
    else if (num <= 2)
        return 1;
    else
        return cal(num - 1) + cal(num - 2);
}

int main()
{
    int num;
    cin >> num;
    cout << cal(num) << "\n";
}