#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(string s)
{
    vector<int> answer;
    vector<int> temp;
    map<int, int> ma;
    int tempNum = 0;
    int counts = 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ',')
        {
            temp.push_back(tempNum);
            tempNum = 0;
        }
        else if ('0' <= s[i] && s[i] <= '9')
        {
            tempNum *= 10;
            tempNum += s[i] - '0';
        }
    }
    temp.push_back(tempNum);
    sort(temp.begin(), temp.end());

    for (int i = 1; i < temp.size(); i++)
    {
        if (temp[i] != temp[i - 1])
        {
            ma.insert({counts, temp[i - 1]});
            counts = 1;
        }
        else
        {
            counts++;
        }
    }
    ma.insert({counts, temp.back()});
    for (auto it = ma.begin(); it != ma.end(); it++)
    {
        answer.push_back(it->second);
    }
    reverse(answer.begin(), answer.end());
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