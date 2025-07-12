#ifndef DISJOINSET_H
#define DISJOINSET_H

#include <stdio.h>
#include <stdlib.h>

typedef struct tagDisjoinSet{
    struct tagDisjoinSet* Parent;
    void* data;
} DisjoinSet;

void DS_UnionSet(DisjoinSet* set1, DisjoinSet* set2);
DisjoinSet* DS_FindSet(DisjoinSet* set);
DisjoinSet* DS_MakeSet(void* NewData);
void DS_DestroySet(DisjoinSet* Set);

#endif
