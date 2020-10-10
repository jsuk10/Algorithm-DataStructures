#include <iostream>
using namespace std;

#define MaxNum 246920
bool *primeArray = new bool[MaxNum];

void Eratos()
{
    int count = 0;
    //초기화
    //전역 변수 선언시 false값으로 초기화 되어 있음.
    for (int i = 2; i <= MaxNum; i++)
        primeArray[i] = true;

    for (int i = 2; i * i <= MaxNum; i++)
    {
        if (primeArray[i] == true)
            for (int j = i * i; j <= MaxNum; j += i)
            {
                primeArray[j] = false;
            }
    }
}

void CheckNum(int num)

{
    int count = 0;
    for (int i = num + 1; i <= 2 * num; i++)
    {
        if (primeArray[i] == true)
            count++;
    }
    cout << count << '\n';
}
int main()
{
    std::ios::sync_with_stdio(false);
    Eratos();

    int num = 1;

    while (true)
    {
        cin >> num;
        if (num == 0)
            break;
        CheckNum(num);
    }
}