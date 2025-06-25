#include "LinkedList.h"

int main(void){
    
    node* sll = sll_create(11);

    return 0;
}
node* sll_create(element_type data){
    node* p = (node*)malloc(1,sizeof(node));
    p->data = data;
    p->NextNode = NULL;
    return p;
}
void sll_destroy(node* sll){
    node * next;
    while(sll != NULL){
        next = sll->NextNode;
        free(sll);
        sll = next;
    }
}
void sll_append(node** sll, node* target){
    if((*sll) == NULL){
        (*sll) = target;
    }
    else{
        node * last = (*sll);
        while( last->NextNode != NULL)
                last = last->NextNode;
    
        last->NextNode = target;
    }
}
node* sll_get(node* sll, int position){
    node* pNode = sll;
    while( pNode != NULL && (position--) >= 0){
        pNode = pNode->NextNode;
    }
    return pNode;
}
// rotation list -> find -> link reset -> remove
void sll_remove(node** sll, node* target){
    node * pNode = sll;
    while(pNode->NextNode != NULL){
        if(pNode->NextNode == target){
            pNode->NextNode = target->NextNode;
            free(target);
        }
        pNode = pNode->NextNode;
    }
}