#include <iostream>

using namespace std;

int queue[10001];
int backIndex = 0;
int frontIndex = 0;
int caseNum;

void Push(int num)
{
    queue[frontIndex++] = num;
}

void Pop()
{
    if (backIndex == frontIndex)
        cout << -1 << "\n";
    else
        cout << queue[backIndex++] << "\n";
}

void Size()
{
    int size = frontIndex - backIndex;
    cout << (size <= 0 ? 0 : size) << "\n";
}

void Empty()
{
    if (frontIndex == backIndex)
        cout << 1 << "\n";
    else
        cout << 0 << "\n";
}

void back()
{
    if (frontIndex == backIndex)
        cout << -1 << "\n";
    else
        cout << queue[frontIndex - 1] << "\n";
}

void front()
{
    if (frontIndex - backIndex <= 0)
        cout << -1 << "\n";
    else
        cout << queue[backIndex] << "\n";
}

void Command()
{
    string commend;
    int number;
    cin >> commend;
    if (commend == "push")
    {
        cin >> number;
        Push(number);
    }
    else if (commend == "pop")
    {
        Pop();
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
        front();
    }
    if (commend == "back")
    {
        back();
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> caseNum;
    for (int i = 0; i < caseNum; i++)
    {
        Command();
    }
}