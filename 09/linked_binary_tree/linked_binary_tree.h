/*******************************************************************
 * Linked binary Tree implementation
 * 
 *                    [BinTree]
 *                       |
 *                    [root]
 *                       |
 *  [left pointer] - [data]- [right pointer]
 *   
 * <ADT> - create, add(left, right) , get, delete
 * 
 *******************************************************************/
#ifndef _LINKED_BINARY_TREE_
#define _LINKED_BINARY_TREE_

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

#endif