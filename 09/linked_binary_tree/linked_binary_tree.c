#include "linked_binary_tree.h"

BinTree* makeBinTree(char data){
    BinTree* BT = (BinTree*)calloc(1,sizeof(BinTree));
    if(BT){
        BinTreeNode* btNode = (BinTreeNode*)calloc(1,sizeof(BinTreeNode));    
        if(btNode){
            btNode->data = data;
            BT->pRootNode = btNode;
        }
    }
    return BT;
}
BinTreeNode* getRootNode(BinTree* BT){
    return BT? BT->pRootNode:NULL;
}

BinTreeNode* getLCNode(BinTree* BT){

}
BinTreeNode* getRCNode(BinTree* BT){

}

BinTreeNode* addLCNode(BinTree* BT,char data){
 
}
BinTreeNode* addRCdNode(BinTree* BT,char data){

}
char getData(BinTree* BT){
    return BT? BT->pRootNode->data:NULL;
}
void deleteBinTree(BinTree* BT){

    
}
