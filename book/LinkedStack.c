#include "LinkedStack.h"

int main(int argc, char* argv[]){
    LinkedStack * pStack = NULL;
    LinkedStackNode* pNode = NULL;

    pStack = createLinkedStack();
    if(pStack != NULL){
        pushLS(pStack,'A');
        pushLS(pStack,'B');
        pushLS(pStack,'C');
        pushLS(pStack,'D');
        displayLinkedStack(pStack);

        
        pNode = popLS(pStack);
        if(pNode != NULL){
            printf("Pop - [%c]\n", pNode->data);
            free(pNode);
        }
        displayLinkedStack(pStack);

        
        pNode = peekLS(pStack);
        if(pNode != NULL){
            printf("Peek - [%c]\n", pNode->data);
        }
        displayLinkedStack(pStack);
        printf("delete Stack...\n");
        deleteLinkedStack(pStack);
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
LinkedStackNode* popLS(LinkedStack* pStack){        //팝.  링크재연결->탑링크 주소 반환
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
        printf("====== STACK ======\n");
        while(p){
            printf("[%d] - [%c]\n", count--, p->data);
            p = p->pLink;
        }
    }
    
}
