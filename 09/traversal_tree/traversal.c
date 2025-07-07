/*******************************************************************
 * Linked binary Tree traversal
 * 
 *******************************************************************/
#include "traversal.h"

int main(void){
    BinTree* pBinTree = NULL;

    BinTreeNode* pNodeA=NULL;
    BinTreeNode* pNodeB=NULL;
    BinTreeNode* pNodeC=NULL;
    BinTreeNode* pNodeD=NULL;
    BinTreeNode* pNodeE=NULL;
    BinTreeNode* pNodeF=NULL;
    BinTreeNode* pNodeG=NULL;

    pBinTree = makeBinTree('A');
    if(pBinTree){
        pNodeA = getRootNode(pBinTree);
        pNodeB = addLCNode(pNodeA,'B');
        pNodeC = addRCNode(pNodeA,'C');
        if(pNodeB){
            pNodeD = addLCNode(pNodeB,'D');
            pNodeE = addRCNode(pNodeB,'E');
        }
        if(pNodeC){
            pNodeF = addLCNode(pNodeC,'F');
            pNodeG = addRCNode(pNodeC,'G');
        }
    }
    
    traversalTree(pBinTree->pRootNode);
    delBinTree(pBinTree);

    return 0;
}
void traversalTree(BinTreeNode* pNode){

    // 1. pre-order traversal
    
    if(pNode){
        printf("%c\n",getData(pNode));      // now node
        traversalTree(pNode->pLeftChild);   // left
        traversalTree(pNode->pRrightChild); // right
    }


}
// create binary tree. [BinTree] -> [root node] -> [left child] [data] [right child] .....
BinTree* makeBinTree(char root_data){
    BinTree* pBinTree = (BinTree*)calloc(1,sizeof(BinTree));
    if(pBinTree){
        pBinTree->pRootNode = makeBinTreeNode(root_data);
        if(pBinTree->pRootNode == NULL){
            free(pBinTree->pRootNode);
            perror("memory allocation error. mkeBinTreeNode()");
        }
    }
    else{
        perror("memory allocation error.makeBinTree()");
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