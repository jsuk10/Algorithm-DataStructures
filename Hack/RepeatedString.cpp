#include <iostream>
#include <vector>
#include <map>

using namespace std;

string st = "";
int number;

int main()
{
    cin >> st >> number;
    int replace = number / st.size();
    int rest = number % st.size();
    int count = 0, restCount = 0;
    for (int i = 1; i < st.size(); i++)
    {
        if (i < rest)
            if (st[i] == 'a')
                restCount++;

        if (st[i] == 'a')
            count++;
    }
    cout << count * replace + restCount;
}
