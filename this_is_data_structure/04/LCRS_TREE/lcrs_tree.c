#include <stdio.h>
#include <stdlib.h>
#include "lcrs_tree.h"

static int CHILD_COUNT; // node count 
static int LEVEL_COUNT;

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

  PrintTree(Root,0);

  FindNode(Root,'B');
  
  printf("Tree Node Count : %d\n", CountChild(Root));

  printf("%d level node = ",0);
  LCRS_PrintNodesAtLevel(Root,0,0);
  printf("\n");
  printf("%d level node = ",1);
  LCRS_PrintNodesAtLevel(Root,1,0);
  printf("\n");
  printf("%d level node = ",2);
  LCRS_PrintNodesAtLevel(Root,2,0);
  printf("\n");

  printf("%d level node = ",3);
  LCRS_PrintNodesAtLevel(Root,3,0);
  printf("\n");
  
  printf("%d level node = ",7);
  LCRS_PrintNodesAtLevel(Root,7,0);
  printf("\n");
  
  DestroyTree(Root);

  return 0;
}
void AddChild(lcrs_node* pNode, lcrs_node* pNew){
  if(pNode->pLC == NULL){     // if not child
    pNode->pLC = pNew;
  }
  else{
    lcrs_node* pFind = pNode->pLC;
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
void DestroyNode(lcrs_node* pNode){
  if(pNode != NULL){
    free(pNode);
  }
}
// recursive delete
int DestroyTree(lcrs_node * pRoot){

  if(pRoot->pRS != NULL)
    DestroyTree(pRoot->pRS);
  if(pRoot->pLC != NULL)
    DestroyTree(pRoot->pLC);
  
  pRoot->pLC = NULL;
  pRoot->pRS = NULL;
  free(pRoot);
}

void FindNode(lcrs_node* pNode, DATA data){

  if(pNode->data == data){
    printf("\nFind !!! %c\n", data);
  }
  if(pNode->pRS != NULL)
    FindNode(pNode->pRS,data);

  if(pNode->pLC != NULL)
    FindNode(pNode->pLC,data);
  
  
}
int PrintTree(lcrs_node* pNode,int Depth){
  
  for(int i=0; i<Depth-1; i++)
    printf("   ");
  if(Depth>0)
    printf("+--");
  
  printf("%c\n",pNode->data);
  
  if(pNode->pLC != NULL)
    PrintTree(pNode->pLC, Depth+1);

  if(pNode->pRS != NULL)
    PrintTree(pNode->pRS,Depth);

}
int CountChild(lcrs_node* pNode){
  if(pNode != NULL){
    CHILD_COUNT++;    //extern int
    CountChild(pNode->pRS);
    CountChild(pNode->pLC);
    return CHILD_COUNT;
  }
  return 0;
}
void LCRS_PrintNodesAtLevel(lcrs_node* pNode,int targetLevel, int currentLevel){
  
  if(targetLevel == currentLevel)
    printf("%c ",pNode->data);
  
  if(pNode->pLC != NULL)
    LCRS_PrintNodesAtLevel(pNode->pLC, targetLevel, currentLevel+1);
    
  if(pNode->pRS != NULL)
    LCRS_PrintNodesAtLevel(pNode->pRS,targetLevel, currentLevel);

}