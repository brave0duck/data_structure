/**
 * - 스택 링크드 리스트를 더불링크드 리스트로 구현
 * - 첨엔 싱글 링크드 리스트로 구현했으나 push는 편한데 pop은 불편함
 * - 접근 편의를 위해 헤더노드에 마지막주소를 저장하는 변수추가. STACK은 마지막만 PUSH,POP하기때문
 * - 접근,추가,삭제 모두 단순 링크드리스트에 비해 유연
 * - 단점: 노드크기증가, 구현이 복잡함
 * 
 *  header[top|*pEnd|*pStart] ->  [*pPrev|data|*pNext]     ->  [*pPrev|data|*pNext]
 *        [크기][끝주소][시작주소]      [이전주소][데이타][다음주소]
 */        
#include "stacklist.h"
#define MAX 1000

int main(void){
    clock_t start, end;

    start = clock();
    Stack * pStack = Create();
    node *pNode;

    printf("Push 1000 elements...\n");
    for(int i=1; i<=MAX; i++){
        pNode = (node*)malloc(sizeof(node));
        pNode->data = i*10;
        Push(pStack,&pNode);
    }
    //Print(pStack);
    
    printf("Pop 500 elements...\n");
    for(int i=1; i <= MAX/2; i++){
        Pop(pStack);
    }
    //Print(pStack);

    printf("delete stack...\n");
    Delete(&pStack);
    
    end = clock();

    printf("running time is %f sec", (end-start)/(double)CLOCKS_PER_SEC);
    return 0;
}

Stack* Create(){
    Stack* p = (Stack*)calloc(1,sizeof(Stack));
    
    return p;
}
int Push(Stack* pStack, node** input){
    
    if(input == NULL){
        perror("memory allocation fail");
        return EOF;
    }
    if(pStack->pStart == NULL){     // if first
        (*input)->pNext = NULL;
        (*input)->pPrev = (node*)pStack;
        pStack->pStart = (*input);
        pStack->pEnd = (*input);
        
    }
    else{                           // not first
        (*input)->pPrev = pStack->pEnd;
        (*input)->pNext = NULL;
        pStack->pEnd->pNext = (*input);
        pStack->pEnd = (*input);
    }

    pStack->top++;
    return 0;
}
int Pop(Stack* pStack){
   if(pStack->top >= 1){        // If there is at least one
        node* tmp = pStack->pEnd->pPrev;    
        free(pStack->pEnd);
        
        tmp->pNext = NULL;
        pStack->pEnd = tmp;
        
        pStack->top--;
        
        return 0;
    }
    else{
        fprintf(stdout,"stack empty\n");
        return 1;
    }

}
int Delete(Stack** ppStack){
    
    if( (*ppStack)->top > 0){   // If there is at least one
        node* pDel = (*ppStack)->pEnd;      // last node
        node* prev_address = pDel->pPrev;   // prev last node

        while( (*ppStack)->top--){
            free(pDel);
            pDel = prev_address;
            prev_address = pDel->pPrev;
        }
    }
    free((*ppStack));   //header node delete
    return 0;
}
int Count(Stack* pStack){
    return pStack->top;
}
void Print(Stack* pStack){
    node* p =pStack->pEnd;
    printf("=====Stack Print=====\n");
    while(p!=NULL && p != (node*)pStack){
        printf("%d\n",p->data);
        p = p->pPrev;
    }
    printf("Stack count : %d\n", Count(pStack));
}