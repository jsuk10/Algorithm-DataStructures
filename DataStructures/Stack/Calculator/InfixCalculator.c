#include <string.h>
#include <stdlib.h>
#include "InfixToPostfix.h"
#include "InfixToPostfix.c"
#include "PostCalculator.h"
#include "PostCalculator.c"

int EvalInfixExp(char exp[])
{
    int len = strlen(exp);
    int ret;
    //문자열 저장공간 마련
    char *expcpy = (char *)malloc(len + 1);
    //복사
    strcpy(expcpy, exp);

    //후위연산으로 변환후 계산기함수 실행
    ConvToRPNExp(expcpy);
    ret = EvalRPNExp(expcpy);
    //메모리 헤제및 값 반환
    free(expcpy);
    return ret;
}
