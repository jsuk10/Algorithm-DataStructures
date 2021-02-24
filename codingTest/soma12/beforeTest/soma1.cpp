#include <iostream>
#include <string>

using namespace std;

int countA, countB;

int main()
{
    string x;
    freopen("input.txt", "r", stdin);

    cin >> x;
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == '('){
            countA++;
            cout <<"A";
        }
        else if (x[i] == ')'){
            countB++;
            cout <<"B";
        }
    }

    if (countA == countB)
        cout << "YES";
    else
    {
        cout << "NO";
    }

    return 0;
}