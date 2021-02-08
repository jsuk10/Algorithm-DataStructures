#include <iostream>

using namespace std;

int SliceNumberSum(int num)
{
    if (num < 10)
        return num;
    int answer = num % 10;
    return answer + SliceNumberSum(num / 10);
}

int SelfNumber(int num)
{
    return num + SliceNumberSum(num);
}

int main()
{
    int Number, selfNumber;

    cin >> Number;
    for (int i = 0; i < Number; i++)
    {
        if (SelfNumber(i) == Number)
        {
            cout << i;
            break;
        }
        if (i == Number - 1)
            cout << 0;
    }
}