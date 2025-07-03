#include "CircleQueue.h"

int QueueInput(int (*pFunc)(Queue*,char), Queue* pQ, char input){
    int i=0;
    
    printf("Input Queue (exit:0) remain count-%d : ", (pQ->max - pQ->current));
    scanf(" %c",&input);

    for(i=0; (i < pQ->max) && (input !='0') ; i++){
        if(pFunc(pQ, input)){
            printf("input fail.Queue full");
            return 0;
        }
        if(!isFull(pQ)){
            printf("Input Queue (exit:0) remain count-%d : ", (pQ->max - pQ->current));
            scanf(" %c", &input);
        }
    }
    return i;
}

int main(int argc,char* argv[]){
    Queue* pQ;    
    Node* pNode;
    char s_input;

    pQ = Create(MAX);
    if(!QueueInput(EnQueue,pQ, s_input))
        printf("EnQueue failed\n");
    // create, enqueue, dequeue, count, print
    Print(pQ);

    printf("\n DeQueue...\n");
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

    printf("if insert Queue insert 'E'? : \n");
    EnQueue(pQ,'E');
    Print(pQ);

    Delete(pQ);
    
    return 0;
}