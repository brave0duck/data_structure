#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int data;
}node;

typedef struct stack{
    int top;
    node* pNode;
}Stack;

Stack* Create(int size);
int Delete(Stack** ppStack);
int Pop(Stack* pStack);
int Push(Stack* pStack, node* input);
int Count(Stack* pStack);
int PrintStack(Stack* pStack);

#endif