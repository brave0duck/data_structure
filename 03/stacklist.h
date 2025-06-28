#ifndef STACKLIST_H
#define STACKLIST_H

#include <stdio.h>
#include <stdlib.h>


typedef struct dll{     // stack double linked list
    int data;
    struct dll* pPrev;
    struct dll* pNext;
}node;

typedef struct stack{
    int top;
    node* pEnd;
    node* pStart;
}Stack;

Stack* Create();
int Delete(Stack** ppStack);
int Push(Stack* pStack, node* input);
int Pop(Stack* pStack);
int Count(Stack* pStack);
void Print(Stack* pStack);

#endif