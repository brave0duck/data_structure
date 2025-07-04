#include "Linked_Queue.h"

Queue* Create(void)
{   Queue* pQ = (Queue*)calloc(1, sizeof(Queue));
    assert(pQ != NULL);
    return pQ;
}
Node* getLastNode(Queue* pQ){
    Node* pNode = pQ->pFront;
    while(pNode != NULL && pNode->pNext != NULL){
        pNode = pNode->pNext;
    }
    return pNode;
}
int EnQueue(Queue* pQ,char data){
    assert(pQ !=NULL);
    Node* pNode = calloc(1,sizeof(Node));
    assert(pNode != NULL);

    if(getLastNode(pQ) == NULL) // if first
        pQ->pFront = pNode;
    else
        pQ->pRear->pNext = pNode;

    pNode->data = data;
    pQ->pRear = pNode;
    pQ->currentCount++;

    return 0;
}
Node* DeQueue(Queue* pQ){
    Node* pReturn = pQ->pFront;
    if(pQ->currentCount > 0){
        pQ->pFront = pQ->pFront->pNext;
        pQ->currentCount--;
    }
    return pReturn;
}

int Delete(Queue * pQ)
{
    if(pQ!=NULL)
    {
        Node* pNext;
        Node * pDel = pQ->pFront;
        while(pDel != NULL)
        {
            pNext = pDel->pNext;
            free(pDel);
            pDel = pNext;
        }
        free(pQ);
        return 0;
    }
    return 1;
}
int Print(Queue* pQ)
{
    if(pQ!=NULL)
    {
        Node * pNode = pQ->pFront;
        for(int i=0; i < pQ->currentCount && pNode!=NULL; i++)
        {
            printf("[%d]-[%c]\n",i,pNode->data);
            pNode = pNode->pNext;
        }
        return 0;
    }
    return 1;
}