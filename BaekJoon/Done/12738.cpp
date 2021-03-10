#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int caseNum, temp;
vector<int> v, v2;

int main()
{
    cin >> caseNum;
    for (int i = 0; i < caseNum; i++)
    {
        cin >> temp;
        v2.push_back(temp);
    }
    v.push_back(v2[0]);

    for (int i = 1; i < caseNum; i++)
    {
        if (v.back() < v2[i])
        {
            v.push_back(v2[i]);
        }
        else
        {
            vector<int>::iterator it = lower_bound(v.begin(), v.end(), v2[i]);
            *it = v2[i];
        }
    }
    cout << v.size();
}