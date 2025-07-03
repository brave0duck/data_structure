#include "QueueArray.h"


int main(int argc, char* argv[]){
    Queue* pQ;    
    Node* pNode;
    // create, enqueue, dequeue, count, print
    pQ = Create(MAX);
    EnQueue(pQ, 'A');
    EnQueue(pQ, 'B');
    EnQueue(pQ, 'C');
    EnQueue(pQ, 'D');
    PrintQueue(pQ);

    pNode = DeQueue(pQ);
    if(pNode != NULL){
        printf("DeQueue value - [%c]\n", pNode->data);
        free(pNode);
    }
    PrintQueue(pQ);

    pNode = peekQueue(pQ);
    if(pNode != NULL){
        printf("peekQueue value - [%c]\n", pNode->data);
    }
    PrintQueue(pQ);

    EnQueue(pQ,'E');
    PrintQueue(pQ);

    Delete(pQ);
    return 0;
}
Queue* Create(int size){
    Queue * pQ = (Queue*)malloc(sizeof(Queue));
    if(pQ != NULL){
        pQ->pNode = (Node*)malloc(MAX*sizeof(Node));
        if(pQ->pNode != NULL){
            pQ->start = 0;
            pQ->end = 0;
        }
    }
    return pQ;
}
int EnQueue(Queue* pQ, char data){
    if( !isFull(pQ)){
        pQ->pNode[pQ->end].data = data;
        pQ->end++;
        return 0;
    }
    else{
        printf("Queue is Full\n");
        return 1;
    }
}
Node* DeQueue(Queue* pQ){
    Node* deNode = NULL;
    if( !isEmpty(pQ)){
        deNode = malloc(sizeof(Node));
        deNode->data = pQ->pNode[pQ->start].data;
        pQ->start++;
    }
    else{
        printf("Queue Empty\n");
    }
    return deNode;
}
Node* peekQueue(Queue* pQ){
    return &(pQ->pNode[pQ->start]);
}
int isEmpty(Queue* pQ){
    if(pQ->end == pQ->start )
        return 1;
    else
        return 0;
}
int isFull(Queue* pQ){
    if( (pQ->end) == (MAX-1))
        return 1;
    else
        return 0;
}
int Delete(Queue * pQ){
    if(pQ != NULL){
        if(pQ->pNode != NULL){
            free(pQ->pNode);
        }
        free(pQ);
        return 0;
    }
    return 1;

}
int CountQueue(Queue* pQ){
    return (pQ->end - pQ->start);

}
int PrintQueue(Queue* pQ){
    printf("=QUEUE SIZE: %d, NODE SIZE : %d\n", MAX, CountQueue(pQ));
    for(int i=pQ->start; i<pQ->end; i++){
        printf("[%d]-[%c]\n",i, pQ->pNode[i].data);
    }
}