#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

vector<int> v, answer;
set<vector<int>> av;
set<string> sets;
int n, m;

void Process(int index)
{
    //size = m되면 셋에 넣음
    if (answer.size() == m)
    {
        av.insert(answer);
        return;
    }

    //중복을 제거하는 백 트래킹
    //arr[i]로 중복 체크함
    for (int i = 0; i < n; i++)
    {
        answer.push_back(v[i]);
        Process(i);
        answer.pop_back();
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n >> m;

    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    //set써서 사실 안해줘도됨
    sort(v.begin(), v.end());
    //과정
    Process(0);

    for (auto iter = av.begin(); iter != av.end(); iter++)
    {
        for (auto j = iter->begin(); j < iter->end(); j++)
        {
            cout << *j << " ";
        }
        cout << "\n";
    }
}