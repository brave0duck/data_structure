/*******************************************************************
 * Linked binary Tree implementation
 * 
 * ADT
 * makeBinTree, getRootNode, addLeftChildNode, addRightChildNode,
 * getLeftChildNode,getRightChildNode,getData, deleteBinTree
 * 
 *******************************************************************/
#ifndef _LINKED_BINARY_TREE_
#define _LINKED_BINARY_TREE_

#include <stdio.h>
//#include <stdlib.h>

typedef struct BinTreeNodeType{
    char data;
    struct BinTreeNodeType* pLeftChild;
    struct BinTreeNodeType* pRrightChild;
}BinTreeNode;

typedef struct BinTreeType{
    struct BinTreeNodeType* pRootNode;
}BinTree;

BinTree* makeBinTree(char data);                            // malloc
BinTreeNode* getRootNode(BinTree* BT);
BinTreeNode* addLCNode(BinTree* BT,char data);              // LC = left child
BinTreeNode* addRCdNode(BinTree* BT,char data);             // RC = right child
BinTreeNode* getLCNode(BinTree* BT);
BinTreeNode* getRCNode(BinTree* BT);
char getData(BinTree* BT);
void deleteBinTree(BinTree* BT);

#endif