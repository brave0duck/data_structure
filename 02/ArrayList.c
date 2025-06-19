#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int Menu(void);

int main(void){
    ArrayList * pList;
    
    pList = createList(_MAX_);

    for(int i=1; i<=8 ; i++){
        addListData(pList,i,i*10);
    }
    getListData(pList, 5);
    getListData(pList, 1);

    getListLength(pList);

    removeListData(pList, 5);
    removeListData(pList, 2);
    removeListData(pList, 8);

    clearList(pList);

    deleteList(pList);

    return 0;
}
// 배열이동 함수
int shiftList(ArrayListNode* p, int a, int b){
    
    if(a > b){  // 배열 왼쪽 이동
        for(int i=b; i<= a; i++){
            p[i] = p[i+1];
        }
    
    }
    else{   // 배열 오른쪽 이동
        for(int i=b; i<= a; i--){
            p[i+1] = p[i];
        }
    
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
        p->pData[position-1].data = data;        // 끼우려는 위치가 전체숫자보다 크면 0리턴
        
    }
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
    if(position > p->current)
        return 0;
    shiftList(p->pData, p->current-1, position-1);
    p->pData[p->current-1].data = 0;

    return 1;
}
void clearList(ArrayList* p){
    for(int i=0; i<p->current; i++){
        p->pData[i].data = 0;
    }
    p->current=0;
    p->max_count=0;
    
}
void deleteList(ArrayList* p){
    while(p){
        free(p->pData);
        p->pData = NULL;
    }
    free(p);
    p=NULL;
    
}