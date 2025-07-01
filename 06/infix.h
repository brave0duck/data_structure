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

