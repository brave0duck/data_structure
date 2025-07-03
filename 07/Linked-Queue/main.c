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