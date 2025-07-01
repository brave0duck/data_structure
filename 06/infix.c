/*
문자열을 입력바고 연산자를 만날때까지 하나씩 이동
연산자를 만나면 스택에서 두 요소를 꺼내서 연산을 한다 ( pop())
연산결과를 스택에 푸쉬한다 ( push())

연산자가 없다. or 끝까지 다 돌았다
스택에 있는 결과를 출력한다
*/
#include "infix.h"
#define MAX 50

LinkedStack* paserToken(char* src);
int calc
int main(int argc, char* argv[]){
    LinkedStack* pStack=NULL;
    LinkedStackNode* pNode = NULL;
    char input[MAX]={0};
    
    printf("Input string (exit:0) : ");
    fgets(input, MAX,stdin);
    input[strcspn(input, "\n")] = 0; // 개행 제거

    while(input[0] !='0'){
        pStack = paserToken(input);

        if(str != NULL){
            printf("%s\n",str);
            free(str);
        }
    
        fflush(stdin);
        printf("Input string (exit:0) : ");
        fgets(input, MAX,stdin);
        input[strcspn(input, "\n")] = 0; // 개행 제거
    }

    return 0;
}    
LinkedStack* createLinkedStack(){               //생성
    LinkedStack* pStack = calloc(1,sizeof(LinkedStack));
    if(pStack == NULL){
        return NULL;
    }
    return pStack;
}
int pushLS(LinkedStack* pStack, char data){     //푸시. 메모리할당->링크 연결 ->끝
    if(pStack != NULL){
        LinkedStackNode *pNode = malloc(sizeof(LinkedStackNode));
        if(pNode != NULL){
            pNode->data = data;
            pNode->pLink = pStack->pTop;
            
            pStack->pTop = pNode;
            pStack->currentCount++;
            return 0;
        }
    }
    return 1;
}
LinkedStackNode* popLS(LinkedStack* pStack){        //팝.  링크재연결->탑링크 주소 반환. 받은쪽이해제
    LinkedStackNode * pNode;
    if(pStack != NULL){
        pNode = pStack->pTop;
        pStack->pTop = pNode->pLink;
        pStack->currentCount--;
        
        pNode->pLink = NULL;
    }
    return pNode;
}
static inline int isEmpty(LinkedStack* pStack){ // 비었나확인. 비었으면 1, 아니면 0
    if(pStack!=NULL && pStack->currentCount > 0)
            return 0;
    return 1;
}
LinkedStackNode* peekLS(LinkedStack* pStack){   //피크. pTop주소반환
    return pStack->pTop;
}
void deleteLinkedStack(LinkedStack* pStack){
    if(pStack != NULL){
        LinkedStackNode* pDel = pStack->pTop;
        LinkedStackNode* pNext;
        while(pDel){
            pNext = pDel->pLink;
            free(pDel);
            pDel = pNext;
        }
        free(pStack);
    }
}
void displayLinkedStack(LinkedStack* pStack){
    if(pStack != NULL){
        LinkedStackNode* p = pStack->pTop;
        int count = pStack->currentCount;
        printf("Node count : %d\n",count);
        while(p){
            printf("[%d] - [%c]\n", count--, p->data);
            p = p->pLink;
        }
    }
    
}
