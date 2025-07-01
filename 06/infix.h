/*
문자열을 입력받아 연산자를 만날때까지 하나씩 이동
연산자를 만나면 스택에서 두 요소를 꺼내서 연산을 한다 ( pop())
연산결과를 스택에 푸쉬한다 ( push())

연산자가 없다. or 끝까지 다 돌았다
스택에 있는 결과를 출력한다

A + ( B * C)
*/

#ifndef _INFIX_H
#define _INFIX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum input_type { LPN, RPN, MLT, DIV, PLS, MNS, OPR} category;

typedef struct TokenType{
    double value;
    category type;
}Token;

typedef struct LinkedStackNodeType{
    Token data;
    struct LinkedStackNodeType* pLink;
}LinkedStackNode;

typedef struct LinkedStackType{
    int currentCount;
    LinkedStackNode* pTop;
}LinkedStack;

LinkedStack* create();	//생성
int push(LinkedStack* pStack, LinkedStackNode* pNode);	//푸시. 메모리할당->링크 연결 ->끝
LinkedStackNode* pop(LinkedStack* pStack);	//팝.  링크재연결->탑링크 주소 반환
static inline int isEmpty(LinkedStack* pStack);	// 비었나확인. 비었으면 1, 아니면 0
LinkedStackNode* peek(LinkedStack* pStack);//피크. pTop주소반환
void delete(LinkedStack* pStack);
void display(LinkedStack* pStack);


double calcToken(LinkedStack *pStack,char* src);
double operation(double a, double b, char op);

#endif

