#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int caseNum;
vector<int> v;
stack<int> s;

void Process()
{
    for (int i = v.size() - 1; i >= 0; i--)
    {
        int tempNum = v[i];
        while (s.size() != 0)
        {
            if (v[i] < s.top())
            {
                break;
            }
            else
                s.pop();
        }
        if (s.size() == 0)
            v[i] = -1;
        else
        {
            v[i] = s.top();
        }
        s.push(tempNum);
    }
}

int main()
{
    cin >> caseNum;
    int temp;
    for (int i = 0; i < caseNum; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    Process();
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}