#include "double-linked-list.h"

Dll_Node* CreateList(void){
    Dll_Node* pHead = (Dll_Node*)malloc(sizeof(Dll_Node));
    if(NULL != pHead){
        pHead->data = 0;
        pHead->pPrev = NULL;
        pHead->pNext = NULL;
    }
    return pHead;

}
void DestroyList(Dll_Node** ppHead){
    // 1. normal while version
    Dll_Node * pDel, * pDelNext;
    pDel = *ppHead;
    pDelNext = (*ppHead)->pNext;

    while(pDel != NULL){
        free(pDel);
        pDel = pDelNext;
        pDelNext = pDel->pNext;
    }

    // 2. recursive version
    // if(pHead->pNext != NULL){
    //     DestroyList(pHead->pNext);
    //     free(pHead);
    // }
}
void AppendNode(Dll_Node** ppHead, Dll_Node* pNew){
    
    if( IsEmptyList(ppHead)){
        (*ppHead) = pNew;
        pNew->pPrev = NULL;
        pNew->pNext = NULL;
    }
    else{
        Dll_Node* pFind = FindLastNode(ppHead);
        pFind->pNext = pNew;
        pNew->pPrev = pFind;
        pNew->pNext = NULL;

    }

}
int IsEmptyList(Dll_Node** ppHead){
    if((*ppHead) == NULL){
        return 1;
    }
    return 0;
}
Dll_Node* FindLastNode(Dll_Node** ppHead){
    Dll_Node* pLast = (*ppHead);
    while( NULL != pLast && NULL != pLast->pNext){
        pLast = pLast->pNext;
    }
    return pLast;
}
Dll_Node* FindFirstNode(Dll_Node ** ppHead){
    if( (*ppHead)->pNext != NULL){
        return (*ppHead)->pNext;
    }
    return *ppHead;
}

Dll_Node* getNode(Dll_Node** ppHead,ElementType data){
    Dll_Node* pFind = (*ppHead);
    while(pFind != NULL){
        if(pFind->data == data){
            return pFind;
        }
        pFind = pFind->pNext;
    }
    return NULL;
}
void DeleteNode(Dll_Node* pHead, Dll_Node* pDel){


}
void InsertNode(Dll_Node** pHead, Dll_Node* pNew){

}
int CountNode(Dll_Node** ppHead){
    Dll_Node* pCount = (*ppHead);
    int nCount=0;
    while( pCount != NULL){
        nCount++;
        pCount = pCount->pNext;
    }
    return nCount;
}