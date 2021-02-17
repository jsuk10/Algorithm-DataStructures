#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[102][100002];
int maxWeight, caseNum;

//우선순위를 비교하기 위한 구조체
class Stuff
{
public:
    int v;
    int w;
    float wpv;

    Stuff(int w, int v)
    {
        this->v = v;
        this->w = w;
        this->wpv = (float)w / (float)v;
    }
};

//우선순위 비교하기 위한 함수
bool Compare(Stuff a, Stuff b)
{
    return a.wpv > b.wpv;
}

//구조체 담을 백터
vector<Stuff> v;

int main()
{
    freopen("input.txt", "r", stdin);
    //구조체 만들기 위해 잠시 받는 변수
    int tempWeight, tempValue;

    //물건수랑, 최대 중량 담음
    cin >> caseNum >> maxWeight;

    //물건 받음
    for (int i = 0; i < caseNum; i++)
    {
        cin >> tempWeight >> tempValue;
        v.push_back(Stuff(tempWeight, tempValue));
    }

    //정렬
    sort(v.begin(), v.end(), Compare);

    //초기값 세팅
    for (int j = v[0].w; j <= maxWeight; j++)
    {
        arr[0][j] = v[0].v;
    }

    //dp
    for (int i = 1; i < caseNum; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            //낮으면 이전거 가지고옴
            if (j - v[i].w < 0)
            {
                arr[i][j] = arr[i - 1][j];
                continue;
            }
            //높으면 배낭에 안 넣을경우 / 넣을 경우중 높은값 가지고옴
            arr[i][j] = max(arr[i - 1][j], v[i].v + arr[i - 1][j - v[i].w]);
        }
    }
    //출력
    
    for (int i = 0; i < caseNum; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    cout << arr[caseNum - 1][maxWeight];
}