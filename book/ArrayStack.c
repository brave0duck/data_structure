#include "ArrayStack.h"

int main(int argc, char* argv[]){

    return 0;
}
//스택 생성
ArrayStack* createStack(int size){
    ArrayStack* pStack = calloc(1,sizeof(ArrayStack));
    if(pStack==NULL)
        return NULL;
    pStack->pData = calloc(size,sizeof(ArrayStackNode));
    if(pStack->pData == NULL)
        return NULL;
    pStack->maxCount = size;
    pStack->currentCount=0;
    return pStack;
}
// 스택 가득찼나 확인. 차면 1, 아니면 0
bool isFull(ArrayStack* pStack){
    if(pStack->currentCount >= pStack->maxCount)
        return True;
    else
        return False;
}
// 스택 비었나 확인. 비었으면 1, 아니면 0
bool isEmpty(ArrayStack* pStack){
    if(pStack->currentCount <= 0)
        return True;
    else
        return False;
}
// 푸시  - 성공0, 실패1
int pushAS(ArrayStack* pStack, char data){
    if(pStack != NULL){
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
    if(pStack != NULL && pNode != NULL && pStack->currentCount > 0){
        pNode->data = pStack->pData[pStack->currentCount-1];
        pStack->currentCount--;

        return pNode;
    }
    else
        return NULL;
}
// 피크. 탑 주소반환
ArrayStackNode* peekAS(ArrayStack* pStack){
    if(pStack!=NULL && pStack->currentCount > 0){
        return pStack->pData[pStack->currentCount-1];
    }
    else
        return NULL;
}
//스택전체 삭제
void deleteArrayStack(ArrayStack* pStack){
    for(int i=0; i<pStack->)

}
//스택출력 - 위에서 아래로 빈칸도 출력
void displayArrayStack(ArrayStack* pStack){

}