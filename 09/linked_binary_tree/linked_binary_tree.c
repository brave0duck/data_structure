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
    return (pNode ? pNode->pLeftChild : NULL);
}
// get right child node
BinTreeNode* getRCNode(BinTreeNode* pNode){
    return (pNode ? pNode->pRrightChild : NULL);
}
// add left child node
BinTreeNode* addLCNode(BinTreeNode* pNode,char data){
    BinTreeNode * pNode = makeBinTreeNode(data);
    if(pNode){
        pNode->pLeftChild = pNode;
    }
    return pNode;
}
// add right child node
BinTreeNode* addRCdNode(BinTreeNode* pNode,char data){
    BinTreeNode * pNode = makeBinTreeNode(data);
    if(pNode){
        pNode->pRrightChild = pNode;
    }
    return pNode;
}
// get data
char getData(BinTreeNode* pBinTreeNode){
    return (pBinTreeNode? pBinTreeNode->data : NULL);
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
void deleteBinTree(BinTree* pBinTree){
    if(pBinTree){
        delBinTreeNode(pBinTree->pRootNode);
        free(pBinTree);
    }
}