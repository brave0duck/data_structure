/**********************************************************
 * Linked List Queue v0.01
 * 
 * ADT - create, delete, enqueue, dequeue, count , print
 *
 ***********************************************************/ 
#include "Linked_Queue.h"

Queue* Create(void)
{   Queue* pQ = (Queue*)calloc(1, sizeof(Queue));
    assert(pQ != NULL);
    return pQ;
}
int EnQueue(Queue* pQ,char data){   // 1. alloc 2. pointer sync 3. currentCount++
    assert(pQ !=NULL);
    Node* pNode = calloc(1,sizeof(Node));
    assert(pNode != NULL);

    if(isEmpty(pQ))                 // if first , connect to header node
        pQ->pFront = pNode;
    else
        pQ->pRear->pNext = pNode;   // if not first, connect last node's next 

    pNode->data = data;         // data input
    pQ->pRear = pNode;          // rear pointer sync
    pQ->currentCount++;         // count+1

    return 0;
}
Node* DeQueue(Queue* pQ){       // 1. find 2. pointer sync 3. currentCount--
    if(isEmpty(pQ)){           // if it is empty
        return NULL;
    }
    else{
        Node* pDel = pQ->pFront;    // pDel = Node address to delete
        if(pDel != NULL){
            pQ->pFront = pDel->pNext;
            pQ->currentCount--;
        }
        return pDel;
    }
}
int Delete(Queue * pQ){
    Node* pDel, *pNext;  // pDel = Node address to delete. 
    if(pQ!=NULL){       // pNext = Next Node address to delete
        pDel = pQ->pFront;
        while(pDel != NULL){
            pNext = pDel->pNext;
            free(pDel);
            pDel = pNext;
        }
        free(pQ);
        return 0;
    }
    return 1;
}
int Print(Queue* pQ){
    if(pQ!=NULL){
        printf("Queue size : %d\n", Count(pQ));
        Node * pNode = pQ->pFront;
        for(int i=0; i < pQ->currentCount && pNode!=NULL; i++){
            printf("[%d]-[%c]\n",i,pNode->data);
            pNode = pNode->pNext;
        }
        return 0;       // ok = 0
    }
    return 1;           // not ok = 1
}