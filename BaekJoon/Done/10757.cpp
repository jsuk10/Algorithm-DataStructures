#include <iostream>
using namespace std;

void Process(string first, string second)
{
    string big, small;
    int start;
    bool isOver = false;
    if (first.length() >= second.length())
    {
        big = first;
        small = second;
    }
    else
    {
        big = second;
        small = first;
    }

    start = big.length() - small.length();

    for (int i = start; i < big.length(); i++)
    {
        big[i] += (small[i - start] - '0');
    }

    for (int i = big.length(); i >= 0; i--)
    {
        if (big[i] > '9')
        {
            if (i != 0)
                big[i - 1]++;
            else
                isOver = true;
            big[i] -= 10;
        }
    }

    if (isOver == true)
        cout << "1";

    cout << big;
}

int main()
{
    string first, second;
    cin >> first >> second;
    Process(first, second);
}