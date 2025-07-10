#include <stdio.h>
#include <stdlib.h>
#include "lcrs_tree.h"

int main(int argc, char** argv){

  lcrs_node* Root = CreateNode('A');
  lcrs_node* B = CreateNode('B');
  lcrs_node* C = CreateNode('C');
  lcrs_node* D = CreateNode('D');
  lcrs_node* E = CreateNode('E');
  lcrs_node* F = CreateNode('F');
  lcrs_node* G = CreateNode('G');
  lcrs_node* H = CreateNode('H');
  lcrs_node* I = CreateNode('I');
  lcrs_node* J = CreateNode('J');
  lcrs_node* K = CreateNode('K');

  AddChild(Root,B);
    AddChild(B,C);
    AddChild(B,D);
      AddChild(D,E);
      AddChild(D,F);

  AddChild(Root,G);
    AddChild(G,H);
  
  AddChild(Root,I);
    AddChild(I,J);
      AddChild(J,K);

  PrintLCRS(Root);

  FindNode(Root,'F');
  FindExNode(Root,'F');

  DestroyLCRS(Root);

  return 0;
}
void AddChild(lcrs_node* pNode, lcrs_node* pNew){
  if(pNode->pLC == NULL){     // if not child
    pNode->pLC = pNew;
  }
  else{
    lcrs_node* pFind = &pNode->pLC;
    while(pFind->pRS != NULL){
      pFind = pFind->pRS;
    }
    pFind->pRS = pNew;
  }
}
lcrs_node* CreateNode(DATA data){
  lcrs_node* pNew = (lcrs_node*)malloc(sizeof(lcrs_node));
  if(pNew){
    pNew->data = data;
    pNew->pLC=NULL;
    pNew->pRS=NULL;
  }
  return pNew;
  
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
lcrs_node* FindNode(lcrs_node* pNode, DATA data){

  lcrs_node* pSlibing;  lcrs_node* pChild;
  pSlibing = pChild = pNode;
  int xpos=1;
  int ypos=1;

  while(pChild != NULL){
    while(pSlibing != NULL){
      if(pSlibing->data == data){
        printf("Find DATA...%d level, %d th node",ypos,xpos);
        return pSlibing;
      }
      pSlibing = pSlibing->pRS;
      xpos++;
    }
    pChild = pChild->pLC;
    pSlibing = pChild;
    ypos++;
  }
  return NULL;
}
// find the previous node of the deleted node.
lcrs_node* FindExNode(lcrs_node* pHead, DATA data){
  // pSlibing = moving ▶▶▶▶▶
  // pChild = moving ▼ ▼ ▼ ▼ ▼
  lcrs_node* pSlibing;  lcrs_node* pChild;
  pSlibing = pChild = pHead;
  
  if(pChild->data == data)
    return pHead;
  // The goal is to find the previous node of the deleted node.
  
  while(pChild != NULL){
    if(pChild->pLC != NULL){
      if(pChild->pLC->data == data)
        return pChild;
    }
    while(pSlibing != NULL){
      
      if(pSlibing->pRS != NULL){
        if(pSlibing->pRS->data == data){
          return pSlibing;
        }
      }
      pSlibing = pSlibing->pRS;
    }
    pChild = pSlibing = pChild->pLC;
  }
  return NULL;
}
//
int PrintLCRS(lcrs_node* pNode){  // level 0 = all node
  
  lcrs_node* pSlibing;  lcrs_node* pChild;
  pSlibing = pChild = pNode;

  while(pChild != NULL){
    while(pSlibing != NULL){
      printf("%c ",pSlibing->data);
      pSlibing = pSlibing->pRS;
    }
    printf("\n|");
    printf("\n|+--");
    pChild = pChild->pLC;
    pSlibing = pChild;
  }
    
}
int CountChild(lcrs_node* pNode){
  lcrs_node* pTemp = pNode;
  int count=0;
  while(pTemp != NULL){
    count++;
    pTemp = pTemp->pLC;
  }
  return count;
}
int CountSlibing(lcrs_node* pNode){
  lcrs_node* pTemp = pNode;
  int count=0;
  while(pTemp != NULL){
    count++;
    pTemp = pTemp->pRS;
  }
  return count;
}
