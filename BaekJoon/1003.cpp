#include <iostream>
using namespace std;

int zero, one;
int arr[41][2];

//전처리를 이용해 모두 계산해줌.
//트리 구조가 동일한점을 이용하여 빠르게 계산가능함
//40개에 2개 씩 게산하는 것으로 계산 횟수는 40 * 2 정도밖에 안됨.
//숫자를 n개로 바꾸면 효율도는 O(2n) 즉 O(n)임.
void fibonacciCal()
{
    arr[0][0] = 1;
    arr[0][1] = 0;
    arr[1][0] = 0;
    arr[1][1] = 1;
    for (int i = 2; i < 41; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            arr[i][j] = arr[i - 1][j] + arr[i - 2][j];
        }
    }
}

int main()
{
    fibonacciCal();
    int num, caseNum;
    cin >> caseNum;
    for (int i = 0; i < caseNum; i++)
    {
        cin >> num;
        cout << arr[num][0] << " " << arr[num][1] << '\n';
    }
}