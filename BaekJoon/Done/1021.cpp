#include <iostream>
#include <list>
using namespace std;

//다음거 참조하는 함수
void next(list<int> &li)
{
    int temp = li.front();
    li.pop_front();
    li.push_back(temp);
}

//이전것 참조하는 함수
void back(list<int> &li)
{
    int temp = li.back();
    li.pop_back();
    li.push_front(temp);
}

//지금 참조 하는게 매치와 맞는지 확인하는 함수
bool match(list<int> &li, int target)
{
    int temp = li.front();
    if (temp == target)
    {
        li.pop_front();
        return true;
    }
    else
    {
        return false;
    }
}

//정방향으로 탐색할것인지 역방향으로 탐색할 것인지 계산
bool choice(list<int> &li, int target)
{
    list<int> frontList(li);
    list<int> backList(li);
    bool findFront = false, findBack = false;
    int frontCount = 0, backCount = 0;
    while (findFront == false)
    {
        if (match(frontList, target) == true)
            break;
        next(frontList);
        frontCount++;
    }

    while (findBack == false)
    {
        if (match(backList, target) == true)
            break;
        back(backList);
        backCount++;
    }

    return frontCount >= backCount ? true : false;
}

int main()
{
    list<int> list;
    int num, targetnum;
    int count = 0, target = 0;
    cin >> num;
    cin >> targetnum;

    for (int i = 1; i <= num; i++)
    {
        list.push_back(i);
    }

    for (int i = 0; i < targetnum; i++)
    {
        cin >> target;
        bool whatChoice = choice(list, target);
        if (!whatChoice)
        {
            while (true)
            {
                if (match(list, target) == true)
                    break;
                next(list);
                count++;
            }
        }
        else
        {
            while (true)
            {
                if (match(list, target) == true)
                    break;
                back(list);
                count++;
            }
        }
    }
    cout << count;
}