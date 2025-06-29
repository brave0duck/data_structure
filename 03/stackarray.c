#include "stackarray.h"
#define MAX 1000

int main(void){
    
    Stack * pStack = Create(MAX);
    node Node;

    clock_t start, end;
    start = clock();

    printf("Push 1000 elements...\n");
    for(int i=1; i<=MAX; i++){
        Node.data = i*10;
        Push(pStack,&Node);
    }
    //PrintStack(pStack);

    printf("Pop 500 elements...\n");
    for(int i=1; i <= MAX/2; i++){
        Pop(pStack);
    }

    //PrintStack(pStack);

    Delete(&pStack);
    printf("delete stack...\n");
    
    end = clock();

    printf("running time is %f sec\n", (end-start)/(double)CLOCKS_PER_SEC);

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
int PrintStack(Stack* pStack){
    if(pStack==NULL)
        return 1;
    printf("====== STACK ======\n");
    for(int i=pStack->top-1; i>= 0; i--){
        printf("%d\n",pStack->pNode[i].data);
    }
    printf("stack count : %d\n", Count(pStack));
    return 0;
}