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
#include "linked_binary_tree.h"

// create binary tree. [BinTree] -> [root node] -> [left child], [right child] .....
BinTree* makeBinTree(char root_data){
    BinTree* pBinTree = (BinTree*)calloc(1,sizeof(BinTree));
    if(pBinTree){
        BinTreeNode* pNode = (BinTreeNode*)calloc(1,sizeof(BinTreeNode));    
        if(pNode){
            pNode->data = root_data;
            pBinTree->pRootNode = pNode;
        }
    }
    return pBinTree;
}
// get root node
BinTreeNode* getRootNode(BinTree* pBinTree){
    return (pBinTree? pBinTree->pRootNode : NULL);
}
// create one node 
BinTreeNode* makeBinTreeNode(char data){
    BinTreeNode* pNode = (BinTreeNode*)calloc(1,sizeof(BinTreeNode));
    if(pNode){      // if not Null
        pNode->data = data;
    }
    return pNode;
}
// get left child node
BinTreeNode* getLCNode(BinTreeNode* pNode){
    return pNode!=NULL ? pNode->pLeftChild : NULL;
}
// get right child node
BinTreeNode* getRCNode(BinTreeNode* pNode){
    return pNode!= NULL ? pNode->pRrightChild : NULL;
}
// add left child node
BinTreeNode* addLCNode(BinTreeNode* pNode,char data){
    BinTreeNode* pChild = makeBinTreeNode(data);
    if(pNode){
        pNode->pLeftChild = pChild;
    }
    return pChild;
}
// add right child node
BinTreeNode* addRCNode(BinTreeNode* pNode,char data){
    BinTreeNode* pChild = makeBinTreeNode(data);
    if(pNode){
        pNode->pRrightChild = pChild;
    }
    return pChild;
}
// get data
char getData(BinTreeNode* pBinTreeNode){
    return pBinTreeNode != NULL ? pBinTreeNode->data: '\0';
}
// recursive delete node. delete all binary tree node
void delBinTreeNode(BinTreeNode* pNode){
    if(pNode){
        delBinTreeNode(pNode->pLeftChild);
        delBinTreeNode(pNode->pRrightChild);
        free(pNode);
    }
}
// delete whole Tree. and delete BinTree itself
void delBinTree(BinTree* pBinTree){
    if(pBinTree){
        delBinTreeNode(pBinTree->pRootNode);
        free(pBinTree);
    }
}