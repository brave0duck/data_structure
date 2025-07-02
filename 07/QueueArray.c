#include "QueueArray.h"
#define MAX 10
#define ERROR  -1
#define OK      0

int main(int argc, char* argv[]){
    Queue* pQ;    
    // create, enqueue, dequeue, count, print
    
    return 0;
}
Queue* Create(int size){
    Queue * pQ = (Queue*)malloc(1,sizeof(Queue));
    if(pQ != NULL){
        pQ->pNode = (Node*)malloc(MAX,sizeof(Node));
        if(pQ->pNode != NULL){
            pQ->front = 0;
            pQ->end = 0;
        }
    }
    return pQ;
}
int EnQueue(Queue* pQ, int data){
    if( !isFull(pQ)){
        pQ->pNode[pQ->end].data = data;
        pQ->end++;
        return OK;
    }
    else{
        printf("Queue Full. Can't EnQueue\n");
        return ERROR;
    }
}
Node* DeQueue(Queue* pQ){
    Node* deNode = NULL;
    if( !isEmpty(pQ)){
        deNode = malloc(sizeof(Node));
        deNode->data = pQ->pNode[pQ->front].data;
        pQ->front++;
    }
    else{
        printf("Queue Empty. Can't DeQueue");
    }
    return deNode;
}
int isEmpty(Queue* pQ){
    if(pQ->end == pQ->front )
        return OK;
    else
        return ERROR;
}
int isFull(Queue* pQ){
    if( (pQ->end - pQ->front) == MAX)
        return OK;
    else
        return ERROR;
}
int Delete(Queue * pQ){

}
int CountQueue(Queue* pQ){

}
int PrintQueue(Queue* pQ){

}