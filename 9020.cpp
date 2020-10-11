#include <iostream>
#include <vector>

using namespace std;

#define MaxNum 10001
bool *primeArray = new bool[MaxNum];
vector<int> primeNum;

int answer1, answer2;

void Eratos()
{
    //초기화
    //전역 변수 선언시 false값으로 초기화 되어 있음.
    for (int i = 2; i <= MaxNum; i++)
        primeArray[i] = true;

    for (int i = 2; i * i <= MaxNum; i++)
    {
        if (primeArray[i] == true)
        	primeNum.push_back(i);
            for (int j = i * i; j <= MaxNum; j += i)
            {
                primeArray[j] = false;
            }
    }
}

void Goldbach()
{
    /*
    소수으면 탈출 하지만 사용하지 않아서 주석 처리했음
    if(primeArray[num] = false){
        return;
    }
    */
	int num;
    cin >> num;
    for (int i = 0; primeNum[i] <= num / 2; i++)
    {
		
        if (primeArray[num - primeNum[i]] == true)
        {
            answer1 = primeNum[i];
            answer2 = num - primeNum[i];
        }
    }
    cout << answer1 << " " << answer2 << "\n";
}

int main()
{
    Eratos();
    int testNum;
	cin >> testNum;
		
	for(int i = 0; i < testNum ; i++){
    Goldbach();
	}
}