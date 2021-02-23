
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

deque<int> dq;
int caseNum;

void PushBack(int num)
{
    dq.push_back(num);
}
void PushFront(int num)
{
    dq.push_front(num);
}

void PopFront()
{
    if (dq.empty() == true)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << dq.front() << "\n";
        dq.pop_front();
    }
}
void PopBack()
{
    if (dq.empty() == true)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << dq.back() << "\n";
        dq.pop_back();
    }
}

void Size()
{
    cout << dq.size() << "\n";
}

void Empty()
{
    cout << ((dq.empty()) ? 1 : 0) << "\n";
}

void Front()
{
    if (dq.empty())
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << dq.front() << "\n";
    }
}

void Back()
{
    if (dq.empty())
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << dq.back() << "\n";
    }
}

void Command()
{
    string commend;
    int number;
    cin >> commend;
    if (commend == "push_front")
    {
        cin >> number;
        PushFront(number);
    }
    else if (commend == "push_back")
    {
        cin >> number;
        PushBack(number);
    }
    else if (commend == "pop_front")
    {
        PopFront();
    }
    else if (commend == "pop_back")
    {
        PopBack();
    }
    else if (commend == "size")
    {
        Size();
    }
    else if (commend == "empty")
    {
        Empty();
    }
    else if (commend == "front")
    {
        Front();
    }
    else if (commend == "back")
        Back();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> caseNum;
    for (int i = 0; i < caseNum; i++)
    {
        Command();
    }
}