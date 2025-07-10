#ifndef TREE_LCRS
#define TREE_LCRS

typedef char DATA;

typedef struct a{
    DATA data;
    struct a* pLC;
    struct a* pRS;
} lcrs_node;

// ADT - CREATE_LCRS, DESTROY_LCRS, ADD_NODE, DELETE_NODE, PRINT_TREE, COUNT_CHILD, COUNT_SLIBING

lcrs_node* CreateNode(DATA data);
int DestroyLCRS(lcrs_node * pNode); 
void AddChild(lcrs_node* pNode, lcrs_node* pNew);
int PrintLCRS(lcrs_node* pNode);  
int CountChild(lcrs_node* pNode);
int CountSlibing(lcrs_node* pNode);
lcrs_node* FindNode(lcrs_node* pNode, DATA data);
lcrs_node* FindExNode(lcrs_node* pHead, DATA data);

#endif