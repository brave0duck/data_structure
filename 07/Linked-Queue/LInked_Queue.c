#include "Linked_Queue.h"

Queue* Create(void)
{   Queue* pQ = (Queue*)calloc(1, sizeof(Queue));
    assert(pQ != NULL);
    return pQ;
}
Node** getLastNode(Queue* pQ,int count){
    Node** ppNode = &(pQ->pFront);
    for(int i=0; i<count ; i++){
        (*ppNode) = (*ppNode)->pNext;
    }
    return ppNode;
}
int EnQueue(Queue* pQ,char data){
    assert(pQ !=NULL);
    Node* pNode = calloc(1,sizeof(Node));
    assert(pNode != NULL);
    
    

    if(pQ->currentCount > 0){
        
        Node** pFind = getLastNode(pQ,pQ->currentCount);

        pFind->pNext = pNode;
        pFind->data = data;
        
        pNode->data = data;
        pQ->pRear = pNode;
        pFind->pNext = pNode;
    }
    else
    {
        /**
         * (*pFind) = pNode;
         */
        pQ->pFront= pNode;
        pQ->pRear = pNode;
        pNode->data = data;
    }
}
Node* DeQueue(Queue* pQ);

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
        for(int i=0; i< pQ->currentCount && pNode!=NULL; i++)
        {
            printf("[%d]-[%c]\n",i,pNode->data);
            pNode = pNode->pNext;
        }
        return 0;
    }
    return 1;
}