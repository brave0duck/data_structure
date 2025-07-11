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
void DestroyNode(lcrs_node* pNode);
int DestroyTree(lcrs_node * pRoot); 
void AddChild(lcrs_node* pNode, lcrs_node* pNew);
int PrintTree(lcrs_node* pNode, int Depth);  
int CountChild(lcrs_node* pNode);
void FindNode(lcrs_node* pNode, DATA data);

void LCRS_PrintNodesAtLevel(lcrs_node* pNode,int targetLevel, int currentLevel);



#endif