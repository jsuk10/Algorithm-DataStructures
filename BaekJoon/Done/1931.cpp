#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//담을 구조체
class Conference
{
public:
    int startTime;
    int endTime;

    Conference()
    {
        cin >> startTime;
        cin >> endTime;
    }

    void Print()
    {
        cout << startTime << " " << endTime << "\n";
    }
};

//sort를 위한 비교함수, end time을 기준으로 정렬함.
bool compare(Conference a, Conference b)
{
    if (a.endTime == b.endTime)
    {
        return a.startTime < b.startTime;
    }
    return a.endTime < b.endTime;
}

int n, answer;
vector<Conference> v;

int main()
{
    cin >> n;
    //객체를 생성해주고 push함
    for (int i = 0; i < n; i++)
    {
        Conference c;
        v.push_back(c);
    }
    //끝나는 시간 별로 정렬함
    sort(v.begin(), v.end(), compare);

    //끝나는 시간이 가장 빠른 것을 선택함
    int endTime = 0;

    for (int i = 0; i < v.size(); i++)
    {
        //이후 시작 시간이 끝나는 시간 이상일 경우 그것을 선택함
        if (v[i].startTime >= endTime)
        {
            answer++;
            //끝나는 시간과 시작 시간이 가장 빠른 것을 선택함.
            endTime = v[i].endTime;
        }
    }
    //답 출력
    cout << answer;
}