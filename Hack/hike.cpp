#include <iostream>
#include <vector>
#include <map>

using namespace std;

int number;
int counts = 0, answer = 0;
bool check = false;
string temp;
string path = "";

int main()
{

    cin >> number;
    cin >> path;

    for (int i = 0; i < path.size(); i++)
    {
        if (path[i] == 'U')
            counts++;
        else if (path[i] == 'D')
            counts--;

        if (counts == 0 && check)
        {
            answer++;
            check = false;
        }
        if (counts < 0)
            check = true;
    }
    cout << answer;
}
