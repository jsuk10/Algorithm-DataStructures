
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answer, v;
int temp, n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);

    cin >> n >> temp;
    v.push_back(temp);

    if (n != 1)
    {
        for (int i = 1; i < n; i++)
        {
            cin >> temp;

            if (v.back() < temp)
            {
                v.push_back(temp);
                answer.assign(v.begin(), v.end());
            }
            else
            {
                auto it = lower_bound(v.begin(), v.end(), temp);
                *it = temp;
            }
        }
    }
    else
    {
        answer.push_back(temp);
    }
    cout << answer.size() << "\n";
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
}