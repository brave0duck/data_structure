#include "disjoinset.h"
// 합집합 연결 - 집합을 연결한다
void DS_UnionSet(DisjoinSet* Set1, DisjoinSet* Set2){
    Set2 = DS_FindSet(Set2);
    Set2->Parent = Set1;
}
// 집합 탐색 연산 - 부모노드를 찾는다
DisjoinSet* DS_FindSet(DisjoinSet* Set){
    while(Set->Parent != NULL)
        Set = Set->Parent;
    return Set;
}
// 노드를 만든다
DisjoinSet* DS_MakeSet(void* NewData){
    DisjoinSet* pSet = (DisjoinSet*)malloc(sizeof(DisjoinSet));
        pSet->data = NewData;
        pSet->Parent = NULL;
    
    return pSet;
}
// 할당 해제
void DS_DestroySet(DisjoinSet* Set){
    if(Set != NULL)
        free(Set);
}