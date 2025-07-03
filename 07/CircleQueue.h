#ifndef _CIRCLE_QUEUE_
#define _CIRCLE_QUEUE_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct n{
    char data;
}Node;

typedef struct q{
    int max;
    int current;
    int start;
    int end;
    Node* pNode;
}Queue;

Queue* Create(int size);
int EnQueue(Queue* pQ,char data);
Node* DeQueue(Queue* pQ);
Node* peek(Queue* pQ);
int isEmpty(Queue* pQ);
int isFull(Queue* pQ);
int Delete(Queue * pQ);
static inline int Count(Queue* pQ);
int Print(Queue* pQ);

int QueueInput(int (*pFunc)(Queue*,char), Queue* pQ, char input);

#endif