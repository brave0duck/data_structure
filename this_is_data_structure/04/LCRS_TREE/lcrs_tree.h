#ifndef TREE_LCRS
#define TREE_LCRS

typedef char DATA;

typedef struct a{
    DATA data;
    struct a* pLC;
    struct a* pRS;
} lcrs_node;


lcrs_node* CreateNode(DATA data);
void DestroyNode(lcrs_node* pNode);
int DestroyTree(lcrs_node * pRoot); 
void AddChild(lcrs_node* pNode, lcrs_node* pNew);
int PrintTree(lcrs_node* pNode, int Depth);  
int CountChild(lcrs_node* pNode);
void FindNode(lcrs_node* pNode, DATA data);

// print target level only
void LCRS_PrintNodesAtLevel(lcrs_node* pNode,int targetLevel, int currentLevel);



#endif