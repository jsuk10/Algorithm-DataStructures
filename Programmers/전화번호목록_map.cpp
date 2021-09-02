#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book)
{
    map<string, bool> map;
    for (auto item : phone_book)
    {
        map.insert(pair<string, bool>(item, true));
    }

    for (int i = 0; i < phone_book.size(); i++)
    {
        string temp = "";
        for (int j = 0; j < phone_book[i].size() - 1; j++)
        {
            temp += phone_book[i][j];
            if (map[temp])
                return false;
        }
    }
    return true;
}