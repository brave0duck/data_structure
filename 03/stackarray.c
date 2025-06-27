#include "stackarray.h"
#define MAX 100

int main(void){

    Stack * pStack = Create(MAX);
    node Node;
    if(Pop(pStack))
        fprintf(stdout,"pop error\n");

    for(int i=1; i<=MAX; i++){
        Node.data = i;
        Push(pStack,&Node);
    }
    printf("Stack count : %d\n", Count(pStack));

    Node.data = 1004;
 
    Push(pStack,&Node);

    printf("Stack count : %d\n", Count(pStack));

    for(int i=1; i <= 20; i++){
        Pop(pStack);
        printf("Stack count : %d\n", Count(pStack));
    }

    Delete(&pStack);
    printf("delete stack...\n");
    
    printf("Stack count : %d\n", Count(pStack));

    return 0;
}

Stack* Create(int size){
    Stack* pStack = malloc(sizeof(Stack));
    if(pStack ==NULL){
        fprintf(stdout,"Stack creation failed");
        return NULL;
    }
    pStack->pNode = malloc(size*sizeof(node));
    if(pStack->pNode == NULL){
        fprintf(stdout,"Node allocation failed");
        return NULL;
    }
    pStack->top=0;
    
    return pStack;
}
int Delete(Stack** ppStack){
    if((*ppStack) !=NULL && (*ppStack)->pNode != NULL){
        (*ppStack)->top=0;
        free((*ppStack)->pNode);
        free((*ppStack));
        *ppStack = NULL;
        
        return 0;
    }
    else{
        fprintf(stdout,"Memory free failed");
        return 1;
    }
}
int Pop(Stack* pStack){
   if(pStack->top >= 1){
        node tmp;
        tmp.data=0;
        pStack->pNode[pStack->top -1] = tmp;
        pStack->top--;
        return 0;
    }
    else{
        fprintf(stdout,"stack empty\n");
        return 1;
    }

}
int Push(Stack* pStack, node* input){
    if(pStack->top >= MAX){
        fprintf(stdout,"stack full\n");
        return 1;
    }
    else{
        pStack->pNode[pStack->top] = *input;
        pStack->top++;
        return 0;
    }
}
int Count(Stack* pStack){
    if(pStack == NULL){
        fprintf(stdout,"Stack delete. can't count node\n");
        return 0;
    }
    return pStack->top;
}