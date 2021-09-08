#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> v;
int number, temp, answer = 0;

int main()
{

    cin >> number;
    for (int i = 0; i < number; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i + 2] == 0)
            i++;
        else if (v[i + 1] == 0)
            ;
        else
            return -1;
        if (i < v.size())
            answer++;
    }
    cout << answer;
}
