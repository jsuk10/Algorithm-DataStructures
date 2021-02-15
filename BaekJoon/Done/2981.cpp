#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int caseNum, arr[101], answer[101], counts,
    temp;

//최대 공약수를 뽑는 함수
int GCD(int a, int b)
{
    int tmp;
    while (b)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> caseNum;
    for (int i = 0; i < caseNum; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + caseNum);
    //모든 차이의 최대 공약수를 뽑음
    temp = arr[1] - arr[0];

    for (int i = 2; i < caseNum; i++)
    {
        temp = GCD(arr[i] - arr[i - 1], temp);
    }

    //약수 찾기
    
    answer[counts++] = temp;
    for (int i = 2; i * i <= temp; i++)
    {
        if (temp % i == 0)
        {
            answer[counts++] = i;
            if (i * i < temp)
                answer[counts++] = temp / i;
        }
    }
    sort(answer, answer + counts);
    for (int i = 0; i < counts; i++)
    {
        cout << answer[i] << " ";
    }
}