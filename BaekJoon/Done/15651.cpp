#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v;

void Process()
{
    if (v.size() == m)
    {
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        v.push_back(i);
        Process();
        v.pop_back();
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    Process();
}