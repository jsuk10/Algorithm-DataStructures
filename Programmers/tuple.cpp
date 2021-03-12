#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;
int arr[100000];
vector<int> ve(100000);

vector<int> solution(string s)
{
    vector<int> answer;
    vector<int> temp;
    set<int> se;
    int tempNum = 0;
    int counts = 0;
    int tempindex = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ',')
        {
            se.insert(tempNum);
            arr[tempNum]++;
            tempNum = 0;
        }
        else if ('0' <= s[i] && s[i] <= '9')
        {
            tempNum *= 10;
            tempNum += s[i] - '0';
        }
    }
    se.insert(tempNum);
    arr[tempNum]++;

    for (auto it = se.begin(); it != se.end(); it++)
    {
        ve[arr[*it]] = *it;
    }
    for (int i = se.size(); i > 0; i--)
    {
        answer.push_back(ve[i]);
    }

    return answer;
}

int main()
{
    string a = "{{2},{2,1},{2,1,3},{2,1,3,4}}";

    vector<int> ve = solution(a);
    for (int i = 0; i < ve.size(); i++)
    {
        cout << ve[i] << " ";
    }
}