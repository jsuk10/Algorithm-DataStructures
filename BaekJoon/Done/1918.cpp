#include <iostream>
#include <stack>

using namespace std;

string a, answer;
stack<char> ops;

//우선순위를 짜주는 함수
int PriorityOp(char op)
{
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else if (op == '(' || op == ')')
        return 0;
    else
        return -1;
}

//스텍을 전부 비우는 함수.
void PopOp(char op)
{
    while (ops.size() != 0)
    {
        if (ops.top() == '(')
            break;
        if (PriorityOp(ops.top()) < PriorityOp(op))
            break;

        answer.push_back(ops.top());
        ops.pop();
    }
}

//연산 속도 줄이려면 미리 캐싱한값 넣기
void pushOps(char c)
{
    if (ops.size() == 0)
    {
        ops.push(c);
        return;
    }

    int topStack = PriorityOp(ops.top());
    int opPriority = PriorityOp(c);
    //괄호의 끝을 만난경우
    if (c == ')')
    {
        char temp = ops.top();
        while (temp != '(')
        {
            answer.push_back(temp);
            ops.pop();
            temp = ops.top();
        }
        ops.pop();
        return;
    }
    //괄호의 시작이거나 새로 들어온 op가 더 클 경우
    else if (opPriority > topStack || opPriority == 0)
    {
        ops.push(c);
        return;
    }
    //새로 들어온 op가 더 작거나 같을 경우
    else
    {
        PopOp(c);
        ops.push(c);
        return;
    }
}

void Change()
{
    for (int i = 0; i < a.size(); i++)
    {
        int priorit = PriorityOp(a[i]);
        if (priorit == -1)
            answer.push_back(a[i]);
        else
            pushOps(a[i]);
    }
    if (ops.size() != 0)
    {
        while (ops.size() != 0)
        {
            if (ops.top() != '(')
                answer.push_back(ops.top());
            ops.pop();
        }
    }
}

int main()
{
    cin >> a;
    Change();
    cout << answer;
}