#include "BinaryTree.h"

SBTree* createSBTree(ElementType data){
    SBTree* pTree = (SBTree*)malloc(sizeof(SBTree));
    if(pTree != NULL){
        pTree->data = data;
        pTree->pLeft = NULL;
        pTree->pRight = NULL;
    }
    return pTree;
}
// POST ORDER DELETE
void destroySBTree(SBTree* pTree){
    if(pTree->pLeft != NULL)
        destroySBTree(pTree->pLeft);
    if(pTree->pRight != NULL)
        destroySBTree(pTree->pRight);

    deleteNode(pTree);

}
void deleteNode(SBTree* pTree){
    if(pTree != NULL)
        free(pTree);
}
//PRE-ORDER = VLR
void preOrderPrint(SBTree* pTree){
    printf("%c ",pTree->data);
    if(pTree->pLeft != NULL)
        preOrderPrint(pTree->pLeft);
    if(pTree->pRight != NULL)
        preOrderPrint(pTree->pRight);
}
// IN-ORDER = LVR
void inOrderPrint(SBTree* pTree){
   
    if(pTree->pLeft != NULL)
        inOrderPrint(pTree->pLeft);
    printf("%c ",pTree->data);
    if(pTree->pRight != NULL)
        inOrderPrint(pTree->pRight);
}
// POST-ORDER = LRV
void postOrderPrint(SBTree* pTree){
    
    if(pTree->pLeft != NULL)
        postOrderPrint(pTree->pLeft);
    if(pTree->pRight != NULL)
        postOrderPrint(pTree->pRight);
    printf("%c ",pTree->data);
}
