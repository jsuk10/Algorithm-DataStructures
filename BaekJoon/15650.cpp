#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[9];
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
        if (arr[i] == 1)
            continue;
        arr[i] = 1;
        v.push_back(i);
        Process(i);
        arr[i] = 0;
        v.pop_back();
    }
}

int main()
{
    cin >> n >> m;
    Process(1);
}