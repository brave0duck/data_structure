#ifndef _QUEUEARRAY_
#define _QUEUEARRAY_

#include <stdio.h>
#include <stdlib.h>


typedef struct n{
    int data;
}Node;

typedef struct q{
    int frond;
    int end;
    Node* pNode;
}Queue;

Queue* Create(int size);
int EnQueue(Queue* pQ);
int DeQueue(Queue* pQ);
int isEmpty(Queue* pQ);
int Delete(Queue * pQ);
int CountQueue(Queue* pQ);
int PrintQueue(Queue* pQ);

#endif