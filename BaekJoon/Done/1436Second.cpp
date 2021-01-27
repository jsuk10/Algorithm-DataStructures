#include <iostream>

using namespace std;

bool Seachss(int num)
{
    if (num % 1000 == 666)
    {
        return true;
    }
    else if (num >= 1000)
        return Seachss(num / 10);
    else if (num < 666)
    {
        return false;
    }
}

void Check(int num)
{
    int count = 0;
    int checknum = 666;
    while (true)
    {
        if (count == num)
        {
            cout << --checknum << "\n";
            break;
        }

        if (Seachss(checknum++) == true)
        {
            count++;
        }
    }
}

int main()
{
    int N;
    cin >> N;
    Check(N);
}