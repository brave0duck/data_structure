#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoublyList.h"

int main(void){
    DoublyList* dll;

    dll = createDoublyList();

    addDoublyListData(dll, 1,10);
    addDoublyListData(dll, 2,20);
    addDoublyListData(dll, 2,30);
    addDoublyListData(dll, 4,40);
    addDoublyListData(dll, 5,50);
    displayDoublyList(dll);

    printf("1 th data is %d\n", getDoublyListData(dll,1));
    printf("3 th data is %d\n", getDoublyListData(dll,3));

    removeDoublyListData(dll,2);
    displayDoublyList(dll);

    deleteDoublyList(dll);

    return 0;
}





DoublyList* createDoublyList(){
    DoublyList * pdll = (DoublyList*)calloc(1, sizeof(DoublyList));
    pdll->currentCount=0;
    pdll->headerNode.pLLink = &(pdll->headerNode);
    pdll->headerNode.pRLink = &(pdll->headerNode);
    return pdll;
}
int getDoublyListData(DoublyList* pList, int position){
    DoublyListNode* pNode= &(pList->headerNode);

    for(int i=1; i<= position;i++){
        pNode = pNode->pRLink;
    }
    return pNode->data;
}
// first input
int addDoublyListData(DoublyList* pList, int position, int data){
    if(position < 1 || position > (pList->currentCount+1)){
        printf("position wrong. there is %d element", pList->currentCount);
        return 0;
    }
    DoublyListNode* pPre = pList->headerNode.pRLink;
    DoublyListNode* pNew = (DoublyListNode*)calloc(1,sizeof(DoublyListNode));

    for(int i=1; i <= position;i++)
        pPre = pPre->pRLink;

    if(position > pList->currentCount){ // last input
        pNew->data = data;
        pNew->pLLink = pPre;
        pNew->pRLink = pList->headerNode.pLLink;
        pPre->pRLink = pNew;
    }
    else{   // insert input
        
        pNew->data = data;
        pNew->pLLink = pPre->pLLink;
        pNew->pRLink = pPre;
        pPre->pLLink = pNew;
        pPre->pRLink = pList->headerNode.pLLink;
    }

    pList->currentCount++;
    return 1;

}
int removeDoublyListData(DoublyList* pList,int position){
    DoublyListNode* pNode = &(pList->headerNode);

    for(int i=1; i<=position;i++){      //find node for delete
        pNode = pNode->pRLink;
    }

    if(pNode->pRLink == pList->headerNode.pLLink){      // if it is last node
        pNode->pLLink->pRLink = pList->headerNode.pLLink;
        pList->headerNode.pLLink = pNode->pLLink->pRLink;
        pNode->pRLink = NULL;
        pNode->pLLink = NULL;
        free(pNode);
    }
    else{       // if middle node
        pNode->pLLink->pRLink = pNode->pRLink;
        pNode->pRLink->pLLink = pNode->pLLink;
        pNode->pLLink = NULL;
        pNode->pRLink = NULL;
        free(pNode);
    }
    pList->currentCount--;
    return 1;
}
int getDoublyListLength(DoublyList* pList){
    return pList->currentCount;
}
void displayDoublyList(DoublyList* pList){
    DoublyListNode* pNode = pList->headerNode.pRLink;
    for(int i=1; i<= pList->currentCount; i++){
        printf("[%d]-%d\n", i, pNode->data);
        pNode = pNode->pRLink;
    }
    printf("\n[%d]node\n",pList->currentCount);

}
void deleteDoublyList(DoublyList* pList){
    DoublyListNode* pNode = pList->headerNode.pRLink;
    DoublyListNode* pNext;

    while(pList->currentCount--){
        pNext = pNode->pRLink;
        free(pNode);
        pNode = pNext;
    }
    free(pList);

}
