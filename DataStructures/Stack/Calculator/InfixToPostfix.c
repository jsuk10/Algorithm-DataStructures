#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../ListStack/ListBaseStack.h"
#include "../ListStack/CustomListBaseStack.c"

int GetOpPrec(char op)
{
	switch (op)
	{
	//곱셈 나눗셈 연산자
	case '*':
	case '/':
		return 3;

	//덧셈 뻴셈 연산자
	case '+':
	case '-':
		return 2;

	//괄호의 시작 연산자 )는 밖에서 따로 관리해준다.
	case '(':
		return 1;
	}

	// 등록되지 않은 연산자
	return -1;
}

//연산자간의 우선순위를 비교해주는 함수
int WhoPrecOp(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec)
		return 1;
	else if (op1Prec < op2Prec)
		return -1;
	else
		return 0;
}

//후위 연산으로 바꿔주는 함수
void ConvToRPNExp(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	//변환된 수식 담는 공간
	char *convExp = (char *)malloc(expLen + 1);

	int i, idx = 0;
	char tok, popOp;

	//배열을 0으로 전부 초기화
	memset(convExp, 0, sizeof(char) * expLen + 1);
	StackInit(&stack);

	//수식을 변환하는 반복문 (convExp에)
	for (i = 0; i < expLen; i++)
	{
		//잠시 담아두는 공간
		tok = exp[i];

		//ctype.h에 있는 인수가 숫자인지 판별하는 함수
		//숫자면 담기
		if (isdigit(tok))
		{
			convExp[idx++] = tok;
		}
		//아니면 witch로 구분
		else
		{
			switch (tok)
			{
			//괄호일 경우
			case '(':
				SPush(&stack, tok);
				break;
			//괄호 막힌경우 모든 연산자를 우측으로 옮겨줌
			case ')':
				while (1)
				{
					popOp = SPop(&stack);
					if (popOp == '(')
						break;
					convExp[idx++] = popOp;
				}
				break;
			//아래 사칙 연산에 걸릴경우 사칙연산들의 우선순위를 고려하여 우측에 넣을지 쌓아둘지 결정함
			case '+':
			case '-':
			case '*':
			case '/':
				while (!SIsEmpty(&stack) &&
					   WhoPrecOp(SPeek(&stack), tok) >= 0)
					convExp[idx++] = SPop(&stack);
				//삽입
				SPush(&stack, tok);
				break;
			}
		}
	}

	//계산이후 스텍에 남은 연산자들을 convExp로 이동함
	while (!SIsEmpty(&stack))
		convExp[idx++] = SPop(&stack);
	//변환된 수식을 원래 배열인 exp에 복사한 뒤에 소멸시킴
	strcpy(exp, convExp);
	free(convExp);
}