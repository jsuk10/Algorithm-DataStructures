#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int caseNum;

class word
{
public:
    string s;

    word(string s)
    {
        this->s = s;
    }
};

bool comp(word a, word b)
{
    if (a.s.size() == b.s.size())
    {
        for (int i = 0; i < a.s.size(); i++)
            if (a.s[i] != b.s[i])
                return a.s[i] < b.s[i];
    }
    else
    {
        return a.s.size() < b.s.size();
    }

    return a.s[0] < b.s[0];
}

int main()
{

    cin >> caseNum;
    string tempS;
    vector<word> pw;
    for (int i = 0; i < caseNum; i++)
    {
        cin >> tempS;
        word w(tempS);
        pw.push_back(w);
    }
    sort(pw.begin(), pw.end(), comp);

    for (int i = 0; i < pw.size() - 1; i++)
    {
        if (pw[i].s == pw[i + 1].s)
        {
            continue;
        }
        cout << pw[i].s << "\n";
    }
    cout << pw[pw.size() - 1].s << "\n";
}