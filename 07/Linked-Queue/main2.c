#include "Linked_Queue.h"

int main(int argc,char* argv[]){
    Queue* pQ = NULL;
    Node* pNode = NULL;

    // create queue
    pQ = Create();
    if(pQ != NULL){
        EnQueue(pQ,'A');
        EnQueue(pQ,'B');
        EnQueue(pQ,'C');
        EnQueue(pQ,'D');
        Print(pQ);

        pNode = DeQueue(pQ);
        if(pNode != NULL){
            printf("DeQueue value -[%c]\n", pNode->data);
            free(pNode);
        }
        Print(pQ);

        pNode = peek(pQ);
        if(pNode != NULL){
            printf("peek value - [%c]\n", pNode->data);
        }
        Print(pQ);

        // add Queue 'E'
        EnQueue(pQ,'E');
        Print(pQ);

        Delete(pQ);

    }
    return 0;
}
