#include "ArrayStack2.h"

int main(int argc, char* argv[]){
    
    ArrayStack* pStack = NULL;
    ArrayStackNode* pNode = NULL;

    pStack = createStack(6);
    if(pStack != NULL){
        pushAS(pStack,10);
        pushAS(pStack,20);
        pushAS(pStack,30);
        pushAS(pStack,40);
        displayArrayStack(pStack);

        
        pNode = popAS(pStack);
        if(pNode != NULL){
            printf("\n\nPop - [%d]\n", pNode->data);
            free(pNode);
        }
        displayArrayStack(pStack);

        
        pNode = peekAS(pStack);
        if(pNode != NULL){
            printf("\n\nPeek - [%d]\n", pNode->data);
        }
        displayArrayStack(pStack);
        printf("delete Stack...\n");
        deleteArrayStack(pStack);
    }
    return 0;
}
//스택 생성
ArrayStack* createStack(int size){
    if(size <= 0)
        return NULL;
    ArrayStack* pReturn = (ArrayStack*)malloc(sizeof(ArrayStack));
    if(pReturn !=NULL){
        memset(pReturn, 0, sizeof(ArrayStack));
        pReturn->maxCount = size;
        pReturn->pData = (ArrayStackNode*)malloc(sizeof(ArrayStackNode));
        if(pReturn->pData != NULL){
                memset(pReturn->pData, 0, sizeof(ArrayStackNode));
        }
        else{
            return NULL;
        }
    }
    return pReturn;

}
// 스택 가득찼나 확인. 차면 1, 아니면 0
static inline int isFull(ArrayStack* pStack){
    if(pStack->currentCount >= pStack->maxCount)
        return 1;
    else
        return 0;
}
// 스택 비었나 확인. 비었으면 1, 아니면 0
static inline int isEmpty(ArrayStack* pStack){
    if(pStack->currentCount <= 0)
        return 1;
    else
        return 0;
}
// 푸시  - 성공0, 실패1
int pushAS(ArrayStack* pStack, int data){
    if(pStack != NULL && !isFull(pStack)){
        pStack->pData[pStack->currentCount].data = data;
        pStack->currentCount++;
        return 0;
    }
    else
        return 1;
}
//팝 - 메모리할당 ->복사-> 반환. 해제는 메인함수에서
ArrayStackNode* popAS(ArrayStack* pStack){
    ArrayStackNode *pNode = malloc(sizeof(ArrayStackNode));
    if(pStack != NULL && pNode != NULL && !isEmpty(pStack)){
        pNode->data = pStack->pData[pStack->currentCount-1].data;
        pStack->currentCount--;

        return pNode;
    }
    else
        return NULL;
}
// 피크. 탑 주소반환
ArrayStackNode* peekAS(ArrayStack* pStack){
    if(pStack!=NULL && !isEmpty(pStack)){
        return &(pStack->pData[pStack->currentCount-1]);
    }
    else
        return NULL;
}
//스택전체 삭제
void deleteArrayStack(ArrayStack* pStack){
    if(pStack!=NULL){
        if(pStack->pData != NULL){
            free(pStack->pData);
        }
        free(pStack);
    }
}
//스택출력 - 위에서 아래로 빈칸도 출력
void displayArrayStack(ArrayStack* pStack){
    int top = pStack->currentCount -1 ;
    int max = pStack->maxCount -1;
    printf("====== STACK ======\n");
    for(int i= max; i >= 0; i--){
        if( i > top)
            printf("[%d] - [Empty]\n",i);
        else
            printf("[%d] - [%d]\n", i, pStack->pData[i]);
    }

}