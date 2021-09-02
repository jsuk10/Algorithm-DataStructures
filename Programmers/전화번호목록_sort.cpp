#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


bool SortSize(string a, string b)
{
    return a.size() < b.size();
}

bool solution(vector<string> phone_book)
{
    sort(phone_book.begin(), phone_book.end());

    string temp;
    for (int i = 0; i < phone_book.size() - 1; i++)
    {
        temp = phone_book[i + 1].substr(0, phone_book[i].size());
        if (temp == phone_book[i])
            return false;
        
    }
    return true;
}