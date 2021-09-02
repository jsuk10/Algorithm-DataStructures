#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    map<string, int> map;
    for (int i = 0; i < participant.size(); i++)
        map[participant[i]]++;

    for (int i = 0; i < completion.size(); i++)
    {
        map[completion[i]]--;
    }

    for (auto xyz : map)
        if (xyz.second != 0)
            return xyz.first;

}