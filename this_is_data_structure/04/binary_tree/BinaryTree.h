#ifndef BINARY_TREE
#define BINARY_TREE

typedef char ElementType;

typedef struct sb{
    ElementType data;
    struct sb* pLeft;
    struct sb* pRight;
}SBTree;

SBTree* createSBTree(ElementType data);
void destroySBTree(SBTree* pTree);
void deleteNode(SBTree* pTree);
void preOrderPrint(SBTree* pTree);
void inOrderPrint(SBTree* pTree);
void postOrderPrint(SBTree* pTree);

#endif