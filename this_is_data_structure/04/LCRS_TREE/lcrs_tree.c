#include <stdio.h>
#include <stdlib.h>
#include "lcrs_tree.h"

int main(int argc, char** argv){
  lcrs_node* pHead = CreateLCRS();


  free(pHead);

  return 0;
}
lcrs_node* CreateLCRS(){
  lcrs_node* pTreeNode = (lcrs_node*)malloc(sizeof(lcrs_node));
  if(pTreeNode == NULL)
    perror("lsrs tree생성에 실패했습니다.");

  return pTreeNode;
}
// recursive delete
int DestroyLCRS(lcrs_node * pNode){

  if(pNode != NULL){
    if(pNode->pLC == NULL && pNode->pRS == NULL){
      printf("%c delete\n", pNode->data);
      free(pNode);
    }
    else{
        DestroyLCRS(pNode->pRS);
        DestroyLCRS(pNode->pLC);
    }
  }
}
int AddChild(lcrs_node* pNode, lcrs_node* pNew){
  if(pNode != NULL && pNew != NULL){
    pNode->pLC = pNew;
    pNew->pLC=NULL;
    pNew->pRS = NULL;

    return 0;   // success
  }
  return 1;     // fail

}
lcrs_node* FindNode(lcrs_node* pNode, DATA data){
  lcrs_node* pSlibing;  lcrs_node* pChild;
  pSlibing = pChild = pNode;

  while(pChild != NULL){
    while(pSlibing != NULL){
      if(pSlibing->data == data){
        return pSlibing;
      }
      pSlibing = pSlibing->pRS;
    }
    pChild = pChild->pLC;
    pSlibing = pChild;
  }
  return NULL:
}
//recursive version
lcrs_node* FindNodeEX(lcrs_node* pNode, DATA data){

  // lcrs_node* pSlibing;  lcrs_node* pChild;
  // pSlibing = pChild = pNode;

  // while(pChild != NULL){
  //   while(pSlibing != NULL){
  //     if(pSlibing->data == data){
  //       return pSlibing;
  //     }
  //     pSlibing = pSlibing->pRS;
  //   }
  //   pChild = pChild->pLC;
  //   pSlibing = pChild;
  // }
  // return NULL:

  lcrs_node* pX;  lcrs_node* pY;
  pX = pY = pNode;

  if(pX->data == data)
    return pX;

  while(pY != NULL){
    while(pX != NULL){
      
    }
  }
   && pY->pLC != NULL){
    while(pX != NULL && pX->pRS != NULL){
      if(pX->pRS->data == data){
        return pX;
      }
      pX = pX->pRS;
    }
    pY = pY->pLC;
    pX = pY;
  }
  return pX->data == data ? pX : NULL;

}
// 
int DeleteNode(lcrs_node* pNode, DATA del){
  if(pNode != NULL){
    lcrs_node* pDel = FinldNode(pNode,del);
    // find prev node
    // pointer link
}
void PrintTree(lcrs_node* pNode, int level){  // level 0 = all node
  if(pNode != NULL){
    switch(level){
      case 0:     // whole print

    }
  }
  if(le)

  printf("")

}
int CountChild(lcrs_node* pNode);
int CountSlibing(lcrs_node* pNode);
