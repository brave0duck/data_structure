#ifndef _CIRCLE_QUEUE_
#define _CIRCLE_QUEUE_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct n{
    char data;
    struct n* pNext;
}Node;

typedef struct q{
    int currentCount;
    Node* pFront;
    Node* pRear;
}Queue;

Queue* Create(void);
int EnQueue(Queue* pQ,char data);
Node* DeQueue(Queue* pQ);
Node* getLastNode(Queue* pQ,int pos);
static inline Node* peek(Queue* pQ){return pQ->pFront;}
static inline int isEmpty(Queue* pQ){ pQ->currentCount ? 0:1;}
static inline int Count(Queue* pQ){return pQ->currentCount;}
int Delete(Queue * pQ);
int Print(Queue* pQ);

int QueueInput(int (*pFunc)(Queue*,char), Queue* pQ, char input);

#endif