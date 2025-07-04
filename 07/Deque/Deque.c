/*-----------------------------------------------------------
 * DeQue 구현 v0.01
 * 덱? 두개의 끝이 있는 큐. 양쪽끝에서 자료의 삽입과 반환이 모두 가능
 * 큐의 프론트와 리어 모두 삭제 가능하도록 구현
 * 
 * ADT - create, delete, isEmpty, insertFront, insertRear,
 * deleteFront, deleteRear, peekFront, peekRear, displayDeque
 *
 ----------------------------------------------------------*/ 
#include "Deque.h"

Queue* createDeque(void)
{   Queue* pQ = (Queue*)calloc(1, sizeof(Queue));
    assert(pQ != NULL);
    return pQ;
}
void deleteDeque(Queue * pQ){
    Node* pDel, *pNext;  // pDel = Node address to delete. 
    if(pQ!=NULL){       // pNext = Next Node address to delete
        pDel = pQ->pFront;
        while(pDel != NULL){
            pNext = pDel->pNext;
            free(pDel);
            pDel = pNext;
        }
        free(pQ);
    }
}
int insertFront(Queue* pQ,char data){
    assert(pQ !=NULL);
    Node* pNode = calloc(1,sizeof(Node));
    assert(pNode != NULL);

    if(isEmpty(pQ)){
        pQ->pFront = pNode;
        pQ->pRear = pNode;
        pNode->data = data;
        pQ->currentCount++;
    }
    else{
        pNode->pNext = pQ->pFront;
        pQ->pFront = pNode;
        pNode->data = data;
        pQ->currentCount++;
    }
    return 0;
}
int insertRear(Queue* pQ,char data){
    assert(pQ !=NULL);
    Node* pNode = calloc(1,sizeof(Node));
    assert(pNode != NULL);

    if(isEmpty(pQ)){
        pQ->pFront = pNode;
        pQ->pRear = pNode;
        pNode->data = data;
        pQ->currentCount++;
    }
    else{
        pQ->pRear->pNext = pNode;
        pQ->pRear = pNode;
        pNode->data = data;
        pQ->currentCount++;
    }
    return 0;
}
Node* deleteFront(Queue* pQ){
    if(isEmpty(pQ)){           // if it is empty
        return NULL;
    }
    else{
        Node* pDel = pQ->pFront;
        pQ->pFront = pDel->pNext;
        pDel->pNext = NULL;
        pQ->currentCount--;
        return pDel;
    }
}
Node* deleteRear(Queue* pQ){
    if(isEmpty(pQ)){           // if it is empty
        return NULL;
    }
    else{
        Node* pFind = pQ->pFront;
        Node* pDel = pQ->pRear;
        for(int i=0; i < pQ->currentCount ; i++){
            if(pFind->pNext == pDel){
                pQ->pRear = pFind;
                pFind->pNext = NULL;
                pQ->currentCount--;
                break;
            }
            pFind = pFind->pNext;
        }
        return pDel;
    }
}
Node* peekFront(Queue* pQ){
    return pQ->pFront;
}
Node* peekRear(Queue* pQ){
    return pQ->pRear;
}
void displayDeque(Queue* pQ){
    if(pQ!=NULL){
        printf("Queue size : %d\n", pQ->currentCount);
        Node * pNode = pQ->pFront;
        for(int i=0; i < pQ->currentCount && pNode!=NULL; i++){
            printf("[%d]-[%c]\n",i,pNode->data);
            pNode = pNode->pNext;
        }
    }
}