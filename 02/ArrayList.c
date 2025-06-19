#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodetype{
    int data;
} ArrayListNode;

typedef struct ArrayListType{
    int max;
    int current;
    ArrayListNode* pData;
} ArrayList;

int createList(int count);
addListData(ArrayList* p,int position, int data);

