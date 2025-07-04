#ifndef _DEQUEUE_
#define _DEQUEUE_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct n{
    char data;
    struct n* pNext;
}Node;

typedef struct q{
    int currentCount;
    Node* pFront;
    Node* pRear;
}Queue;

Queue* createDeque(void);
void deleteDeque(Queue * pQ);
static inline int isEmpty(Queue* pQ){return (pQ->currentCount>0)?0:1;}
int insertFront(Queue* pQ,char data);
int insertRear(Queue* pQ, char data);
Node* deleteFront(Queue* pQ);
Node* deleteRear(Queue* pQ);
Node* peekFront(Queue* pQ);
Node* peekRear(Queue* pQ);
void displayDeque(Queue* pQ);

#endif