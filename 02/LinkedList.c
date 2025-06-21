#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkedListNodeType{
    int data;
    struct LinkedListNodeType * pLink;
} LinkedListNode;

typedef struct LinkedListType{
    int currentCount;
    LinkedListNode headerNode;
} LinkedList;

LinkedList* createLinkedList();
int getLinkedListData(LinkedList* pList, int position);
LinkedListNode* getLinkedListPointer(LinkdedList* pList, int position);
int main(void){

    return 0;
}

LinkedList* createLinkedList(){
    LinkedList* pReturn = (LinkedList*)malloc(sizeof(LinkedList));
    memset(pReturn, 0, sizeof(LinkedList));
    return pReturn;
}

int getLinkedListData(LinkedList* pList, int position){
    LinkedListNode* pCurrentNode = &(pList->headerNode);

    for(int i=1; i<=position;i++)
        pCurrentNode = pCurrentNode->pLink;
    return pCurrentNode->data;
}
LinkedListNode* getLinkedListPointer(LinkdedList* pList, int position){
    
    LinkedListNode* pCurrentNode = &(pList->headerNode);

    for(int i=1; i<=position;i++)
        pCurrentNode = pCurrentNode->pLink;
    return pCurrentNode;
}

int addLinkedListData(LinkedList* pList, int position, int data){
    LinkedListNode* pBefore, *pAfter, *pNew;
    if(pList->currentCount >= position){        //position의 주소 + position-1의 주소가 필요하다
        pBefore = getLinkedListPointer(pList,position-1);
        pAfter = getLinkedListPointer(pList,position);

        pNew = calloc(1,sizeof(LinkedListNode));
        pNew->data = data;
        pNew->pLink = pAfter;

        pBefore->pLink = &pNew;
    }
    else{
        
        pAfter = calloc(1,sizeof(LinkedListNode));
        pAfter->data = data;
        pAfter->pLink = NULL;

        pBefore = getLinkedListPointer(pList, pList->currentCount);
        pBefore->pLink = &pAfter;
    }

    pList->currentCount++;
}