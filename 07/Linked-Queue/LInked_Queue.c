#include "Linked_Queue.h"

int main(int argc,char* argv[])
{

    Queue* pQ;    
    Node* pNode;
    char input;

    // Queue ADT
    // create, delete, EnQueue, DeQueue, isEmpty, isFull, Count, Print

    pQ = Create();
    if(pQ == NULL){
        printf("Queue Create fail!");
        return 1;
    }
    printf("\n[%d] in Queue.\n", QueueInput(EnQueue,pQ, input));
    Print(pQ);

    printf("DeQueue...\n");
    pNode = DeQueue(pQ);
    if(pNode != NULL){
        printf("DeQueue value - [%c]\n", pNode->data);
        free(pNode);
    }
    Print(pQ);
    
    printf("\n peekQueue...\n");
    pNode = peek(pQ);
    if(pNode != NULL){
        printf("peekQueue value - [%c]\n", pNode->data);
    }
    Print(pQ);

    printf("if insert Queue insert 'S'? : \n");
    EnQueue(pQ,'S');
    printf("if insert Queue insert 'Z'? : \n");
    EnQueue(pQ,'Z');
    Print(pQ);

    Delete(pQ);
    
    return 0;
}
int QueueInput(int (*pFunc)(Queue*,char), Queue* pQ, char input){
    int i=0;
    
    printf("Input Queue (exit:0) : ");
    scanf(" %c",&input);

    while( input !='0')// until queue max and input '0' exit
    {
        if(pFunc(pQ, input)){       // <---- call func pointer
            printf("input fail.Queue full");
            return 0;
        }
        printf("Input Queue (exit:0) : ");
        scanf(" %c", &input);
        
    }
    return pQ->currentCount;
}

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