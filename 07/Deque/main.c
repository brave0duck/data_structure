#include "Deque.h"

int main(int argc,char* argv[]){
    Queue* pQ = NULL;
    Node* pNode = NULL;

    // create queue
    pQ = createDeque();
    if(pQ != NULL){
        insertFront(pQ,'A');
        insertFront(pQ,'B');
        insertFront(pQ,'C');
        insertRear(pQ,'D');

        displayDeque(pQ);

        pNode = deleteFront(pQ);
        if(pNode != NULL){
            printf("deleteFront -[%c]\n", pNode->data);
            free(pNode);
        }
        displayDeque(pQ);

        pNode = peekFront(pQ);
        if(pNode != NULL){
            printf("peekFront - [%c]\n", pNode->data);
        }
        displayDeque(pQ);

        // add Queue 'E'
        insertRear(pQ,'E');
        displayDeque(pQ);

        deleteDeque(pQ);

    }
    return 0;
}
