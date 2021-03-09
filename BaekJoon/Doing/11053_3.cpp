
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//두개 다 입력 받은것을 기록함
int caseNum, arr[1001];
//v는 최장 증가 수열 기록 및 갱신용
//indexV는 인덱스를 기록해서 나중에 역으로 answer에 저장
vector<int> v, indexV, answer;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> caseNum;
    for (int i = 0; i < caseNum; i++)
    {
        cin >> arr[i];
    }

    //초기값 세팅
    v.push_back(arr[0]);
    indexV.push_back(0);

    //크면 답 벡터에 추가 하고 작으면 lower_bound를 이용해 값 바꿔줌
    //동시에 indexV에 현재 기록된 index기록
    for (int i = 1; i < caseNum; i++)
    {
        if (v.back() < arr[i])
        {
            v.push_back(arr[i]);
            indexV.push_back(v.size() - 1);
        }
        else
        {
            auto it = lower_bound(v.begin(), v.end(), arr[i]);
            *it = arr[i];
            indexV.push_back(it - v.begin());
        }
    }
    //count를 이용해서 역순 조회 하며으로 출력
    int count = v.size() - 1;
    for (int i = caseNum; i >= 0; i--)
    {
        if (count == indexV[i])
        {
            count--;
            answer.push_back(arr[i]);
        }
    }
    cout << v.size() << "\n";

    for (int i = answer.size() - 1; i >= 0; i--)
    {
        cout << answer[i] << " ";
    }
}