#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoublyList.h"

int main(void){
    DoublyList* dll;

    dll = createDoublyList();       // double linked list = dll

    addDoublyListData(dll, 1,10);
    addDoublyListData(dll, 2,20);
    addDoublyListData(dll, 2,30);
    displayDoublyList(dll);

    printf("1th data delete.\n");
    removeDoublyListData(dll,1);
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
    DoublyListNode* pPre = &(pList->headerNode);
    DoublyListNode* pNew = (DoublyListNode*)calloc(1,sizeof(DoublyListNode));

    if(pNew == NULL){
        perror("Memory allocation failed...");
        return 0;
    }
    for(int i=1; i < position;i++)
        pPre = pPre->pRLink;

    if(position > pList->currentCount){             // last input . ex) a - (b)
        pNew->data = data;                          // b.data = data
        pNew->pLLink = pPre;                        // <Left-link>.b.xxxx = a address
        pNew->pRLink = pList->headerNode.pLLink;    // xxxx.b.<Right-link> = header address
        pPre->pRLink = pNew;                        // xxxx.a.<Right-link> = b address
        
    }
    else{                                           // insert input. ex) a - (b) - c
        
        pNew->data = data;                          // b.data = data
        pNew->pLLink = pPre;                        //  <Left-link>. b . xxxx = a address
        pNew->pRLink = pPre->pRLink;                // xxxx.b.<Right-link> = c address
        
        pPre->pRLink->pLLink = pNew;                // <Left-link>.c.xxxx = b address
        pPre->pRLink = pNew;                        // xxxx.a.<Right-link> = b address
        
    }

    pList->currentCount++;                          // member + 1
    return 1;

}
int removeDoublyListData(DoublyList* pList,int position){
    if( position < 1 || position > (pList->currentCount + 1)){
        printf("Wrong input node position. now node [%d]\n", 0, pList->currentCount);
        return 0;
    }
    DoublyListNode* pNode = &(pList->headerNode);

    for(int i=1; i<=position;i++){      //find node for delete
        pNode = pNode->pRLink;
    }

    if(pNode->pRLink == pList->headerNode.pLLink){   // if last node
        pNode->pLLink->pRLink = pList->headerNode.pLLink;
        pList->headerNode.pLLink = pNode->pLLink->pRLink;
        pNode->pRLink = NULL;
        pNode->pLLink = NULL;
        free(pNode);
    }
    else{                                           // if middle node
        pNode->pLLink->pRLink = pNode->pRLink;
        pNode->pRLink->pLLink = pNode->pLLink;
        pNode->pLLink = NULL;
        pNode->pRLink = NULL;
        free(pNode);
    }
    pList->currentCount--;                          // member - 1
    return 1;
}
int getDoublyListLength(DoublyList* pList){
    return pList->currentCount;
}
void displayDoublyList(DoublyList* pList){
    DoublyListNode* pNode = pList->headerNode.pRLink;
    printf("====================================\n");
    for(int i=1; i<= pList->currentCount; i++){
        printf("[%d]-%d\n", i, pNode->data);
        pNode = pNode->pRLink;
    }
    printf("total : %d node\n",pList->currentCount);
    printf("====================================\n");

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
