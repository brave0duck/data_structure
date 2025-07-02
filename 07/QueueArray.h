#ifndef _QUEUEARRAY_
#define _QUEUEARRAY_

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct n{
    char data;
}Node;

typedef struct q{
    int front;
    int end;
    Node* pNode;
}Queue;

Queue* Create(int size);
int EnQueue(Queue* pQ,char data);
Node* DeQueue(Queue* pQ);
Node* peekQueue(Queue* pQ);
int isEmpty(Queue* pQ);
int isFull(Queue* pQ);
int Delete(Queue * pQ);
int CountQueue(Queue* pQ);
int PrintQueue(Queue* pQ);

#endif
