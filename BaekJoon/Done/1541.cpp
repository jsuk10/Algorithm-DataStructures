#include <iostream>
#include <vector>

using namespace std;

vector<int> numV;
vector<char> opV;

void Parsing(string ex)
{
    int tempNum = 0;
    for (int i = 0; i < ex.size(); i++)
    {
        if ('0' <= ex[i] && ex[i] <= '9')
        {
            //0~9까지 문자가 오면 int형으로 변환
            tempNum += ex[i] - '0';
            tempNum *= 10;
        }
        else
        {
            //숫자 푸쉬 및 초기화
            numV.push_back(tempNum / 10);
            tempNum = 0;
            //연산자 push
            opV.push_back(ex[i]);
        }
    }
    //마지막 남은수 하나 push
    numV.push_back(tempNum / 10);

    // 파싱이 성공적인지 출력
}

void Calculation()
{
    int tempIndex = 0;
    bool flag = false;
    //+값들을 미리계산하고 뒷자리에 0채워넣음
    //op의 숫자는 num의 숫자 -1개 있으므로 op의 index와 +1의 인덱스를 연산
    for (int i = 0; i < opV.size(); i++)
    {
        if (opV[i] == '+')
        {
            if (flag == false)
            {
                numV[i] = numV[i] + numV[i + 1];
                //차후에 모든 인자를 마이너스 하기 때문에 계산하고 0으로 만들어줌.
                numV[i + 1] = 0;
                tempIndex = i;
                flag = true;
            }
            else
            {
                //연속으로 +나올 경우
                numV[tempIndex] += numV[i + 1];
                numV[i + 1] = 0;
            }
        }
        else
        {
            //-가 나올경우 플래그 초기화
            flag = false;
        }
    }

    // for (int i = 0; i < numV.size(); i++)
    //     cout << numV[i] << " ";

    // + 계산 이후 남은 숫자를 전부 빼주어 numV[0]에 저장
    for (int i = 1; i < numV.size(); i++)
    {
        numV[0] -= numV[i];
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    //문자열 받고 파싱한 뒤 계산함.
    string expression;
    cin >> expression;
    Parsing(expression);
    Calculation();
    cout << numV[0] << "\n";
}