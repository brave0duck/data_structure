#include <stdio.h>
#include <stdlib.h>
#define _MAX_ 10

// 노드 타입
typedef struct ArrayListNodeType{
    int data;
} ArrayListNode;

// 배열리스트 타입
typedef struct ArrayListType{
    int max_count;
    int current;
    ArrayListNode* pData;
} ArrayList;


// 생성, 추가, 읽기, 길이, 삭제, 비우기, 전체삭제
ArrayList* createList(int count);
int addListData(ArrayList *p, int position, int data);
int getListData(ArrayList* p, int position);
int getListLength(ArrayList *p);
int removeListData(ArrayList* p, int position);
void clearList(ArrayList* p);
void deleteList(ArrayList* p);


int main(void){
    ArrayList * pList;
    
    pList = createList(_MAX_);

    for(int i=1; i<=8 ; i++){
        addListData(pList,i,i*10);
    }
    addListData(pList,1,49);

    printf("getListData(pList, 5) == %d\n", getListData(pList, 5));
    printf("getListData(pList, 1) == %d\n", getListData(pList, 1));

    printf("getListLength(pList) == %d\n", getListLength(pList));

    for(int i=0; i< (pList->current -1); i++)
        printf("[%d]\t", pList->pData[i].data);

    printf("\n now. after removeListData(pList,1 ) operation \n");
    removeListData(pList, 1);
    for(int i=0; i< (pList->current -1); i++)
        printf("[%d]\t", pList->pData[i].data);
    printf("\n");

    printf("\n now. after removeListData(pList, 6) operation \n");
    removeListData(pList, 6);
    for(int i=0; i< (pList->current -1); i++)
        printf("[%d]\t", pList->pData[i].data);
    printf("\n");
    
    printf("\n now. after removeListData(pList, 2) operation \n");
    removeListData(pList, 2);
    for(int i=0; i< (pList->current -1); i++)
        printf("[%d]\t", pList->pData[i].data);
    printf("\n");

    clearList(pList);

    deleteList(pList);
    
    return 0;
}
// 배열이동 함수. 추가시 오른쪽이동, 삭제시 왼쪽이동 
int shiftList(ArrayListNode* p, int a, int b){
    
    if(a > b){  // 배열 왼쪽 이동. 예) 6,2 = 6번째부터 2번째까지 왼쪽으로 이동. 처음부터 끝으로 이동하면서
        for(int i=b; i<= a; i++)
            p[i] = p[i+1];
    }
    else{   // 배열 오른쪽 이동. 예) 2,5 = 2번째 부터 5번째까지 오른쪽으로 이동. 끝부터 처음으로 이동하면서
        for(int i=b; i<= a; i--)
            p[i+1] = p[i];
    }
}
// 리스트* 생성(갯수)
ArrayList* createList(int count){
    ArrayList* p = (ArrayList*)malloc(sizeof(ArrayList));
    p->max_count = count;
    p->current = 0;
    p->pData = (ArrayListNode*)calloc(count,sizeof(ArrayListNode));

    return p;
}

int addListData(ArrayList *p, int position, int data){
    if( position < p->current){              // 중간에 끼어드면 . 데이터시프트 함수호출
        shiftList(p->pData, position-1, p->current-1);
        p->pData[position].data = data;

    }
    else{       
        p->pData[position-1].data = data;        // 끼우려는 위치가 전체숫자보다 크면 마지막에 추가
        
    }
    p->current++;       // current count +1
    return 1;
}
int getListData(ArrayList* p, int position){
        if(position >= p->current)
            return 0;
        return p->pData[position-1].data;
}
int getListLength(ArrayList *p){
    return p->current;
}
int removeListData(ArrayList* p, int position){
    if(position > p->current){
        printf("Wrong position.. there is no Node\n");
        return 0;
    }

    shiftList(p->pData, p->current-1, position-1);
    p->pData[p->current-1].data = 0;
    p->current--;       // current count -1
    return 1;
}
void clearList(ArrayList* p){
    for(int i=0; i<p->current; i++){
        p->pData[i].data = 0;
    }
    p->current=0;
    p->max_count=0;
    printf("\n clearList...\n");
    
}
void deleteList(ArrayList* p){
    
    free(p->pData);
    p->pData = NULL;
    free(p);
    p=NULL;
    printf("\n deleteList...\n");
}