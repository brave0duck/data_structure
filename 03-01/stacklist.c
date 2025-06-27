/**
 * 스택 링크드 리스트를 더불링크드 리스트로 구현함
 * -첨엔 싱글 링크드 리스트로 구현했으나 push는 편한데 pop은 불편함이 여전함
 * - 링크드리스트의 단점을 보완하고자 헤더노드에 마지막주소를 저장하는 변수추가
 * - 이렇게되면 접근,추가,삭제 연산 모두 링크드리스트에 비해 유연함.
 * - 단점: 노드크기증가, 구현이 복잡함
 */
#include "stacklist.h"
#define MAX 10

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

    if(!Print(pStack))
        printf("%d ==stack==\n",pStack->top);
        
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
    Stack* p = calloc(1,sizeof(Stack));
    return p;
}
int Push(Stack* pStack, node* input){
    
    if(input == NULL){
        perror("memory allocation fail");
        return EOF;
    }
    if(pStack->pStart == NULL){     // if first
        pStack->pStart = input;
        pStack->pEnd = input;
        input->pNext = NULL;
        input->pPrev = pStack->pStart;
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
   if(pStack->top >= 1){
        node* tmp = pStack->pEnd->pPrev;
        tmp->pNext = NULL;
        pStack->pEnd = tmp;

        free(pStack->pEnd);
        pStack->top--;
        
        return 0;
    }
    else{
        fprintf(stdout,"stack empty\n");
        return 1;
    }

}

int Delete(Stack** ppStack){
    
}

int Count(Stack* pStack){
    return pStack->top;
}
int PrintStack(Stack* pStack){
    node* p =pStack->pEnd;
    if(pStack->top >=1 && p !=NULL){

        printf("====== STACK ======\n");
        for(int i=pStack->top; i> 0; i--){
            printf("%d stack: %d\n", i, p->data);
            p = p->pNext;
        }
        printf("====== STACK ======\n");
    }
    return 0;
}