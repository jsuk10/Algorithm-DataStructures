
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> V1, V2;
    int Size = 0, TempNumber;
    cin >> Size;
    for (int i = 0; i < Size; i++)
    {
        cin >> TempNumber;
        V1.push_back(TempNumber);
    }
    V2 = V1;
    //중복제거 오름차순
    sort(V2.begin(), V2.end());
    V2.erase(unique(V2.begin(), V2.end()), V2.end());

    for (int i = 0; i < V1.size(); i++)
    {
        auto iter = lower_bound(V2.begin(), V2.end(), V1[i]);
        cout << iter - V2.begin() << " ";
    }
}