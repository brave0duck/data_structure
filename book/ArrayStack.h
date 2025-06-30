#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <stdio.h>
#include <stdlib.h>


typedef struct ArrayStackNodeType{
	char data;
} ArrayStackNode;

typedef struct ArrayStackType{
	int maxCount;
	int currentCount;
	ArrayStackNode* pData;
} ArrayStack;

ArrayStack* createStack(int size);	//스택 생성
static inline int isFull(ArrayStack* pStack);	// 스택 가득찼나 확인. 차면 1, 아니면 0
static inline int isEmpty(ArrayStack* pStack);	// 스택 비었나 확인. 비었으면 1, 아니면 0
int pushAS(ArrayStack* pStack, char data);	// 푸시  - 성공0, 실패1
ArrayStackNode* popAS(ArrayStack* pStack);	//팝 - 메모리할당 ->복사-> 반환. 해제는 메인함수에서
ArrayStackNode* peekAS(ArrayStack* pStack);	// 피크. 탑 주소반환
void deleteArrayStack(ArrayStack* pStack);	//스택전체 삭제
void displayArrayStack(ArrayStack* pStack);	//스택출력 - 위에서 아래로 빈칸도 출력

#endif