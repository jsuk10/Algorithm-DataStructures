//https://www.acmicpc.net/problem/1978

#include <iostream>

using namespace std;

int InputNum(int num)
{
    if (num < 2)
        return 0;

    //first
    //for (int i = 2; i < num; i++)
    //second
    //for (int i = 2 ; i <=num; i++)

    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int casenum, num, count = 0;
    cin >> casenum;
    for (int i = 0; i < casenum; i++)
    {
        cin >> num;
        count += InputNum(num);
    }
    cout << count;
}
