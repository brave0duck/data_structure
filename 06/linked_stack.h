#ifndef _LINKED_STACK_
#define _LINKED_STACK_

typedef struct LinkedStackNodeType{
	char data;
	struct LinkedStackNodeType* pLink;
} LinkedStackNode;

typedef struct LinkedStackNode{
	int currentCount;
	LinkedStackNode* pTop;
}LinkedStack;


LinkedStack* createLinkedStack();	//생성
int pushLS(LinkedStack* pStack, char data);	//푸시. 메모리할당->링크 연결 ->끝
LinkedStackNode* popLS(LinkedStack* pStack);	//팝.  링크재연결->탑링크 주소 반환
static inline int isEmpty(LinkedStack* pStack);	// 비었나확인. 비었으면 1, 아니면 0
LinkedStackNode* peekLS(LinkedStack* pStack);//피크. pTop주소반환
void deleteLinkedStack(LinkedStack* pStack);
void displayLinkedStack(LinkedStack* pStack);

#endif