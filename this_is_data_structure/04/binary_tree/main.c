#include "BinaryTree.h"

int main(int, char**){

    SBTree* A = createSBTree('A');
    SBTree* B = createSBTree('B');
    SBTree* C = createSBTree('C');
    SBTree* D = createSBTree('D');
    SBTree* E = createSBTree('E');
    SBTree* F = createSBTree('F');
    SBTree* G = createSBTree('G');

    A->pLeft = B;
    B->pLeft = C;
    B->pRight = D;

    A->pRight = E;
    E->pLeft = F;
    E->pRight = G;

    printf("pre-order ...\n");
    preOrderPrint(A);
    printf("\n\n");

    printf("in-order ...\n");
    inOrderPrint(A);
    printf("\n\n");
    
    printf("post-order ...\n");
    postOrderPrint(A);
    printf("\n\n");
    
    return 0;
}
