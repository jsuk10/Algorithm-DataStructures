#include <iostream>
using namespace std;

#define MaxNum 1000001
bool *primeArray = new bool[MaxNum];

void Eratos(int end)
{
    //초기화
    //전역 변수 선언시 false값으로 초기화 되어 있음.
    for (int i = 2; i <= end; i++)
        primeArray[i] = true;

    for (int i = 2; i * i <= end; i++)
    {
        if (primeArray[i] == true)
            for (int j = i * i; j <= end; j += i)
                primeArray[j] = false;
    }
}

void InputNum(int start, int last)
{
    for (int i = start; i <= last; i++)
    {
        if (primeArray[i] == true)
            cout << i << "\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);

    int start, end;
    cin >> start >> end;
    Eratos(end);
    InputNum(start, end);
}
