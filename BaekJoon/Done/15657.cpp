#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v, answer;
int arr[8];
int n, m;

void Process(int index)
{
    if (answer.size() == m)
    {
        for (int i = 0; i < answer.size(); i++)
        {
            cout << answer[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = index; i < n; i++)
    {
        answer.push_back(v[i]);
        Process(i);
        answer.pop_back();
    }
}

int main()
{
    cin >> n >> m;

    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());
    Process(0);
}