#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define MaxSize 20

int board[MaxSize + 1][MaxSize + 1];
int caseNum;
vector<int> v1, v2;
int *arr;
int minnum = 9999999;

void combiV()
{
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < v1.size(); i++)
    {
        for (int j = i + 1; j < v1.size(); j++)
        {
            sum1 += board[v1[i]][v1[j]] + board[v1[j]][v1[i]];
            sum2 += board[v2[i]][v2[j]] + board[v2[j]][v2[i]];
        }
    }
    int div = abs(sum1 - sum2);

    if (minnum > div)
        minnum = div;
}

//n개를 입력 받고 조합 출력하는 함수
void Process(int j, int count)
{
    if (count == caseNum / 2)
    {
        for (int i = 1; i < caseNum + 1; i++)
        {
            if (arr[i] == 0)
                v1.push_back(i);
            else
                v2.push_back(i);
        }
        combiV();
        v1.clear();
        v2.clear();
        return;
    }

    for (int i = j + 1; i <= caseNum; i++)
    {
        count++;
        arr[i] = 1;
        Process(i, count);
        count--;
        arr[i] = 0;
    }
}

int main()
{
    cin >> caseNum;
    arr = new int[caseNum + 1]();

    for (int i = 1; i <= caseNum; i++)
    {
        for (int j = 1; j <= caseNum; j++)
        {
            cin >> board[i][j];
        }
    }
    Process(0, 0);
    cout << minnum;
}