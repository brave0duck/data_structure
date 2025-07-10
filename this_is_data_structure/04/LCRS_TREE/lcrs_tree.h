#ifndef TREE_LCRS_H
#define TREE_LCRS_H

typedef char DATA;

typedef struct a{
    DATA data;
    struct a* pLC;
    struct a* pRS;
} lcrs_node;

// ADT - CREATE_LCRS, DESTROY_LCRS, ADD_NODE, DELETE_NODE, PRINT_TREE, COUNT_CHILD, COUNT_SLIBING

lcrs_node* CreateLCRS();
int DestroyLCRS(lcrs_node * pNode); 
int AddChild(lcrs_node* pNode, lcrs_node* pNew);
int AddSlibing(lcrs_node* pNode, lcrs_node* pNew);
int DeleteNode(lcrs_node* pNode)
void PrintTree(lcrs_node* pNode, int level);  // level 0 = all node
int CountChild(lcrs_node* pNode);
int CountSlibing(lcrs_node* pNode);
lcrs_node* FindNode(lcrs_node* pNode, DATA data);
lcrs_node* FindNodeEX(lcrs_node* pNode, DATA data);

#endif