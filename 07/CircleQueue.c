#include "CircleQueue.h"

// start = -1, end= -1 cause circle formula (x = x+1 % MAX)
Queue* Create(int size){
    Queue * pQ = (Queue*)malloc(sizeof(Queue));
    if(pQ != NULL){
        pQ->pNode = (Node*)malloc(size*sizeof(Node));    // all init zero
        if(pQ->pNode == NULL)
            return NULL;
        pQ->start = -1; 
        pQ->end = -1;
        pQ->current =0;
        pQ->max = size;
    }
    return pQ;
}

// insert Queue = First In First Out.
int EnQueue(Queue* pQ, char data){
    if( !isFull(pQ)){
        int pos = (pQ->end+1) % (pQ->max);
        pQ->pNode[pos].data = data;
        pQ->end++;
        pQ->current++;
        return 0;
    }
    return 1;
}
Node* DeQueue(Queue* pQ){
    Node* deNode = NULL;
    if( !isEmpty(pQ)){
        int pos = pQ->start + 1 % MAX;
        deNode = malloc(sizeof(Node));
        if(deNode == NULL)
            return NULL;
        deNode->data = pQ->pNode[pos].data;
        pQ->start++;
        pQ->current--;
    }
    return deNode;
}
Node* peek(Queue* pQ){
    int pos = (pQ->start + 1) % pQ->max;
    return &(pQ->pNode[pos]);
}
int isEmpty(Queue* pQ){
    if(pQ->current == 0){
        printf("Queue Empty\n");
        return 1;
    }
    return 0;
}
int isFull(Queue* pQ){
    if( pQ->current == pQ->max){
        printf("Queue Full\n");
        return 1;
    }
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
static inline int Count(Queue* pQ){
    return pQ->current;

}
// this is key circle queue
// pos's boundry = if MAX is 10, pos is from 0 to 9
int Print(Queue* pQ){
    int size = pQ->current;
    int pos = (pQ->start +1) % pQ->max;
    printf("=QUEUE SIZE: %d, NODE SIZE : %d\n", pQ->max, Count(pQ));
    while(size--){
        printf("[%d]-[%c]\n",pos, pQ->pNode[pos].data);
        pos = (pos + 1) % pQ->max;
    }
}
