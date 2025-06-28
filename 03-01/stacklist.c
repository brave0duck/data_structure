/**
 * 스택 링크드 리스트를 더불링크드 리스트로 구현함
 * -첨엔 싱글 링크드 리스트로 구현했으나 push는 편한데 pop은 불편함
 * - 헤더노드에 마지막주소를 저장하는 변수추가
 * - 이렇게되면 접근,추가,삭제 연산 모두 링크드리스트에 비해 유연
 * - 단점: 노드크기증가, 구현이 복잡함
 * 
 * header[top|*pEnd|*pStart] ->[*pPrev|data|*pNext]->[*pPrev|data|*pNext]
 */
#include "stacklist.h"
#define MAX 5

int main(void){
    
    Stack * pStack = Create();
    node Node;

    printf("1 Pop()\n");
    if(Pop(pStack))
        fprintf(stdout,"pop error\n");

    printf("1 to MAX Push()\n");
    for(int i=1; i<=MAX; i++){
        Node.data = i;
        Push(pStack,&Node);
    }
    printf("Stack count : %d\n", Count(pStack));

    Print(pStack);

    printf("20 Pop()\n");
    for(int i=1; i <= 2; i++){
        Pop(pStack);
    }
    Print(pStack);

    Delete(&pStack);
    printf("delete stack...\n");
    
    return 0;
}

Stack* Create(){
    Stack* p = (Stack*)malloc(sizeof(Stack));
    p->top=0;
    p->pStart = (node*)p;
    p->pEnd = (node*)p;

    return p;
}
int Push(Stack* pStack, node* input){
    
    if(input == NULL){
        perror("memory allocation fail");
        return EOF;
    }
    if(pStack->pStart == NULL){     // if first
        input->pNext = NULL;
        input->pPrev = pStack->pStart;
        pStack->pStart = input;
        pStack->pEnd = input;
        
    }
    else{                           // not first
        input->pPrev = pStack->pEnd;
        input->pNext = NULL;
        pStack->pEnd->pNext = input;
        pStack->pEnd = input;
    }

    pStack->top++;
 
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
        node* pDel = (*ppStack)->pEnd;
        node* prev_address = pDel->pPrev;

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
    while(p!=NULL && p != (node*)pStack){
        printf("%d\n",p->data);
        p = p->pPrev;
    }
}