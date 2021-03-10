
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1001], arr[1001], n, maxSize, maxIndex;
vector<int> v[1001], answer;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        v[i].push_back(arr[i]);
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > v[j].back())
            {
                if (v[i].size() < v[j].size() + 1)
                {
                    v[i] = v[j];
                    v[i].push_back(arr[i]);
                    if (maxSize < v[i].size())
                    {
                        maxSize = v[i].size();
                        maxIndex = i;
                    }
                }
            }
        }
    }

    cout << v[maxIndex].size() << "\n";
    for (int i = 0; i < v[maxIndex].size(); i++)
        cout << v[maxIndex][i] << " ";
}