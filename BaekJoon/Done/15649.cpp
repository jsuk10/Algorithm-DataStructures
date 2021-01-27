#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[9];
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
        if (arr[i] == 1)
            continue;
        arr[i] = 1;
        v.push_back(i);
        Process();
        arr[i] = 0;
        v.pop_back();
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    Process();
}