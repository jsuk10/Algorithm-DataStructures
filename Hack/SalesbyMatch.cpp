#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int number, temp, answer;
    vector<int> v;
    map<int, vector<int>> m;

    freopen("input.txt", "r", stdin);

    cin >> number;
    for (int i = 0; i < number; i++)
    {
        cin >> temp;
        m[temp].push_back(0);
    }

    for (auto a : m)
    {
        answer += a.second.size() / 2;
    }
    cout << answer;
}