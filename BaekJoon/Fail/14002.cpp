
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int caseNum, arr[1000];
vector<int> v, answer;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);

    cin >> caseNum;
    for (int i = 0; i < caseNum; i++)
    {
        cin >> arr[i];
    }
    v.push_back(arr[0]);

    for (int i = 1; i < caseNum; i++)
    {
        if (v.back() < arr[i])
        {
            v.push_back(arr[i]);
            answer.assign(v.begin(), v.end());
        }
        else
        {
            auto it = lower_bound(v.begin(), v.end(), arr[i]);
            *it = arr[i];
        }
    }
    cout << answer.size() << "\n";
    for (int i = 0; i < v.size(); i++)
        cout << answer[i] << " ";
}