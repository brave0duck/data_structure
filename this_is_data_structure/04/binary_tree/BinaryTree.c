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
void destroySBTree(SBTree* pTree){

}
void deleteNode(SBTree* pTree){

}
void preOrderPrint(SBTree* pTree){

}
void inOrderPrint(SBTree* pTree){

}
void postOrderPrint(SBTree* pTree){

}
