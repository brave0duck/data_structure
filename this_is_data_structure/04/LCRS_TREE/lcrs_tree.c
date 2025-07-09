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
  lcrs_node* pFind = pNode;
  if(pFind != NULL){
      while(1){
        if(pFind->data == data){
          return pFind;
        }
        pFind = pFind->pLC;
        
      }

      return pFind;
    }

  }
  


  
}
int DeleteNode(lcrs_node* pNode, DATA del){
  if(pNode != NULL){
    while(pNode->data != del){
      if(pNode->pRS != NULL){

      }
      
    }


  }
}
void PrintTree(lcrs_node* pNode, int level);  // level 0 = all node
int CountChild(lcrs_node* pNode);
int CountSlibing(lcrs_node* pNode);
