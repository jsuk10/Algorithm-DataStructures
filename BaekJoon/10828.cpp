#include <iostream>

using namespace std;

int stack[10001];
int postition = 0;
int caseNum;

void Push(int num)
{
    stack[postition++] = num;
}

void Pop()
{
    if (postition <= 0)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << stack[(postition--) - 1] << "\n";
    }
}

void Size()
{
    if (postition <= 0)
    {
        cout << 0 << "\n";
    }
    else
    {
        cout << postition << "\n";
    }
}

void Empty()
{
    cout << ((postition > 0) ? 0 : 1) << "\n";
}

void Top()
{
    if (postition <= 0)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << stack[postition - 1] << "\n";
    }
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
    else if (commend == "top")
    {
        Top();
    }
}

int main()
{
    cin >> caseNum;
    for (int i = 0; i < caseNum; i++)
    {
        Command();
    }
}