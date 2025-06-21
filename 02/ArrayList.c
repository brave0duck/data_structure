#include <stdio.h>
#include <stdlib.h>


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
    int count;
    pList = createList(5);

    if(pList==NULL){
        printf("failed create... \n");
        return 1;
    }
        
    addListData(pList,0,10);
    addListData(pList,1,40);
    addListData(pList,1,30);
    addListData(pList,2,60);

    count = getListLength(pList);
    printf("getListLength() is %d", count);
   
    clearList(pList);

    deleteList(pList);
    
    return 0;
}
// 배열이동 함수. 노드추가시 오른쪽이동, 삭제시 왼쪽이동 
int shiftList(ArrayListNode* p, int a, int b){
    
    if(a > b){  // 삭제연산. 배열 왼쪽이동. 예) 6,2 = 6번째부터 2번째까지 왼쪽으로 이동
        for(int i=b; i< a; i++)
            p[i] = p[i+1];
    }
    else{   // (a <b) 추가연산. 배열 오른쪽이동. 예) 2,5 = 2번째 부터 5번째까지 오른쪽으로 이동
        for(int i=b; i > a; i--)
            p[i+1] = p[i];
    }
}
// 리스트* 생성(갯수)
ArrayList* createList(int count){
    if(count <= 0 || count > _MAX_)
        return NULL;
    ArrayList* p = (ArrayList*)malloc(sizeof(ArrayList));
    p->max_count = count;
    p->current = 0;
    p->pData = (ArrayListNode*)calloc(count,sizeof(ArrayListNode));

    return p;
}

int addListData(ArrayList *p, int position, int data){
    if( p == NULL)
        return 1;
    // position의 위치가 0미만이거나 current값을 초과하면 잘못입력된 것
    if( position < 0 || position > p->current || p->current >= p->max_count)
        return 2;
    if( position < p->current)              // 중간에 끼어들면 데이터 시프트 함수 호출
        shiftList(p->pData, position, p->current-1);
    
    p->pData[position].data = data;        // 마지막에 추가
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
    //p->max_count=0;
    printf("\n clearList...\n");
    
}
void deleteList(ArrayList* p){
    if(p!=NULL){
        if(p->pData[0].data != 0)
            clearList(p);
        free(p->pData);
        free(p);
    }
    
    printf("\n deleteList...\n");
}