#include "QueueArray.h"
#define MAX 10

int main(int argc, char* argv[]){
    Queue* pQ;    
    // create, enqueue, dequeue, count, print
    
    return 0;
}
Queue* Create(int size){
    Queue * pQ = (Queue*)calloc(1,sizeof(Queue));
    if(pQ != NULL){
        pQ->pNode = (Node*)calloc(MAX,sizeof(Node));
        if(pQ->pNode != NULL){
            pQ->frond = 0;
            pQ->end = MAX -1;
        }
    }
    return pQ;
}
int EnQueue(Queue* pQ){

}
int DeQueue(Queue* pQ){

}
int isEmpty(Queue* pQ){

}
int Delete(Queue * pQ){

}
int CountQueue(Queue* pQ){

}
int PrintQueue(Queue* pQ){

}