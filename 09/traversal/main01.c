#include "linked_binary_tree.h"

int main(void){
    BinTree* pBinTree = NULL;
   
    BinTreeNode* pNodeA=NULL;
    BinTreeNode* pNodeB=NULL;
    BinTreeNode* pNodeC=NULL;
    BinTreeNode* pNodeD=NULL;
    BinTreeNode* pNodeE=NULL;
    BinTreeNode* pNodeF=NULL;

    pBinTree = makeBinTree('A');
    if(pBinTree){
        pNodeA = getRootNode(pBinTree);
        pNodeB = addLCNode(pNodeA,'B');
        pNodeC = addRCNode(pNodeA,'C');
        if(pNodeB){
            pNodeD = addLCNode(pNodeB,'D');
        }
        if(pNodeC){
            pNodeE = addLCNode(pNodeC,'E');
            pNodeF = addRCNode(pNodeC,'F');
        }
    }
    traversalTree(pBinTree);
    
    delBinTree(pBinTree);

    return 0;
}