#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));

    vector<string> names, copyNames;
    string name;
    int problemNum, peopleNum;
    char overlap;

    cout << "인원수를 입력해주세요\n";
    cin >> peopleNum;
    cout << "사람의 이름을 입력해 주세요\n";
    for (int i = 0; i < peopleNum; i++)
    {
        cin >> name;
        names.push_back(name);
    }
    cout << "문제의 개수를 입력해주세요\n";
    cin >> problemNum;

    cout << "중복이 가능합니까? (Y이외에는 전부 N)";
    cin >> overlap;

    if (overlap == 'Y' || overlap == 'y')
    {
        for (int i = 0; i < problemNum; i++)
        {
            cout << i + 1 << "번문제는 " << names[rand() % names.size()] << "입니다\n";
        }
    }
    else
    {
        for (int i = 0; i < problemNum; i++)
        {
            if (copyNames.size() == 0)
                copyNames = names;

            int temp = rand() % copyNames.size();
            cout << i + 1 << "번문제는 " << copyNames[temp] << "입니다\n";
            copyNames.erase(copyNames.begin() + temp);
        }
    }
}