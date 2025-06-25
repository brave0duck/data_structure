#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int element_type;
typedef struct tagnode{
    element_type data;
    struct tagnode* NextNode;
}node;

node* sll_create(element_type data);
void sll_destroy(node* a);
void sll_append(node** sll, node* target);
void sll_insert_after(node* sll, node* target);
void sll_insert_newhead(node** sll, node* target);
void sll_remove(node** sll, node* target);
node* sll_get(node* sll, int position);
int sll_count(node* sll);


#endif
