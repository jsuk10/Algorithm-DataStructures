#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v, answer;
int n, temp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    cin >> temp;
    v.push_back(temp);

    for (int i = 1; i < n; i++)
    {
        cin >> temp;
        if (temp > v.back())
        {
            v.push_back(temp);
        }
        else
        {
            auto it = lower_bound(v.begin(), v.end(), temp);
            *it = temp;
        }
    }

    cout << v.size();
}