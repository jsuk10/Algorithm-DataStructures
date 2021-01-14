#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../ListStack/ListBaseStack.h"
#include "../ListStack/CustomListBaseStack.c"

int EvalRPNExp(char exp[])
{
    Stack stack;
    int expLen = strlen(exp);
    char tok, op1, op2;

    StackInit(&stack);

    for (int i = 0; i < expLen; i++)
    {
        tok = exp[i];
        if (isdigit(tok))
        {
            SPush(&stack, tok - '0');
        }
        else
        {
            op2 = SPop(&stack);
            op1 = SPop(&stack);
            if (tok == '+')
            {
                SPush(&stack, op1 + op2);
            }
            else if (tok == '-')
            {
                SPush(&stack, op1 - op2);
            }
            else if (tok == '*')
            {
                SPush(&stack, op1 * op2);
            }
            else if (tok == '/')
            {
                SPush(&stack, op1 / op2);
            }
        }
    }
    return SPop(&stack);
}