#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct tagNode{
    ElementType data;
    struct tagNode* pPrev;
    struct tagNode* pNext;
}Dll_Node;

//  ADT
Dll_Node* CreateList(void);
void DestroyList(Dll_Node** ppHead);
void AppendNode(Dll_Node** ppHead, Dll_Node* pNew);
Dll_Node* getNode(Dll_Node** ppHead, ElementType data);
void DeleteNode(Dll_Node** ppHead, Dll_Node* pDel);
void InsertNode(Dll_Node** ppHead, Dll_Node* pNew);
int CountNode(Dll_Node** ppHead);

// useful func
int IsEmptyList(Dll_Node ** ppHead);
Dll_Node* FindLastNode(Dll_Node** ppHead);
DLL_Node* FindFisrtNode(Dll_Node** ppHead);


#endif