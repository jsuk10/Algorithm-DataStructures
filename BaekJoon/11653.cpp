#include <iostream>
using namespace std;

void Process(int num)
{
    if (num == 1)
        return;
    else if (num == 2)
    {
        cout << num;
        return;
    }
    else
    {
        for (int i = 2; i < num; i++)
        {
            if (i == num - 1)
            {
                cout << num << '\n';
                return;
            }
            if (num % i == 0)
            {
                cout << i << '\n';
                Process(num / i);
                return;
            }
        }
    }
}

int main()
{
    int num;
    cin >> num;
    Process(num);
}
