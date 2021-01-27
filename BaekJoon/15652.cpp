#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v;

void Process(int j)
{
    if (v.size() == m)
    {
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = j; i <= n; i++)
    {
        v.push_back(i);
        Process(i);
        v.pop_back();
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    Process(1);
}