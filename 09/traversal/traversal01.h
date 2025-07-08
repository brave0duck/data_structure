/*******************************************************************
 * Linked binary Tree Traversal
 * 
 *******************************************************************/
#ifndef _TRAVERSAL_01_
#define _TRAVERSAL_01_

#include <stdio.h>
#include <stdlib.h>

typedef struct BinTreeNodeType{
    char data;
    struct BinTreeNodeType* pLeftChild;
    struct BinTreeNodeType* pRrightChild;
}BinTreeNode;

typedef struct BinTreeType{
    struct BinTreeNodeType* pRootNode;
}BinTree;

BinTree* makeBinTree(char root_data);                            // malloc
BinTreeNode* getRootNode(BinTree* pBinTree);
BinTreeNode* makeBinTreeNode(char data);
BinTreeNode* addLCNode(BinTreeNode* pNode,char data);              // LC = left child
BinTreeNode* addRCNode(BinTreeNode* pNode,char data);             // RC = right child
BinTreeNode* getLCNode(BinTreeNode* pNode);
BinTreeNode* getRCNode(BinTreeNode* pNode);
char getData(BinTreeNode* pNode);
void delBinTreeNode(BinTreeNode* pNode);
void delBinTree(BinTree* pBinTree);

void traversalTree(BinTreeNode *pNode);

#endif