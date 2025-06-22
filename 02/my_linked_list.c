#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ll_node{     //alias. linked list node = ll_node
    int data;
    struct ll_node* p;
}node;

typedef struct ll_type{
    int count;
    node start_node;
}linked_list;

linked_list* create(void);
int getData(linked_list* p, int n);
int addData(linked_list* p, int n, int data);
int removeData(linked_list* p, int n);
void deleteData(linked_list* p);
int getLen(linked_list* p);
void printData(linked_list* p);

int main(int argc, char* argv[]){
    linked_list * pList = NULL;
    int value=0;

    pList = create();
    addData(pList,1,10);
    printData(pList); printf("\n");
    addData(pList,2,20);
    printData(pList);printf("\n");
    addData(pList,2,30);
    addData(pList,4,40);
    addData(pList,5,50);
    addData(pList,6,60);
    addData(pList,7,70);
    printData(pList);printf("\n");

    value = getData(pList,2);
    printf("위치: %d, 값: %d\n", 2, value);

    removeData(pList,1);
    printData(pList);

    deleteData(pList);
    

    return 0;
}
linked_list* create(void){
    linked_list* p  = (linked_list*)calloc(1,sizeof(linked_list));
    return p;
}
int getData(linked_list* p, int n){
    node * tmp = &(p->start_node);
    for(int i=1; i<=n;i++)
        tmp = tmp->p;
    return tmp->data;
}

int addData(linked_list* p, int n, int data){
    if( n < 0 || n > (p->count+1)){
        printf("wrong position node is [%d] ~ [%d]\n", 0, p->count);
        return 0;
    }
    node* pre = &(p->start_node);
    node* new = calloc(1,sizeof(node));

    if(n > p->count){   // 마지막에 추가하는경우
        for(int i=1; i<= p->count; i++) // i<= p->count ==> 마지막노드
            pre = pre->p;
        pre->p = new;
        new->p = NULL;
        new->data = data;
    }
    else if(n <= p->count){     // 중간에 끼우는경우. 
                                // 1.할당 2.할당p = (마지막노드 -1) p  3.마지막-1노드 = 할당p
        for(int i=1; i< n;i++){ // i< n == (마지막노드 -1)
           pre = pre->p;        // pre == (마지막 -1) 노드 주소
        }
        new->p = pre->p;
        pre->p = new;
        new->data = data;
        
    }
    p->count++;
    return 1;
}
int getLen(linked_list* p){
    return p->count;
}
void printData(linked_list* p){
    node* pre = p->start_node.p;
    for(int i=1; i<= p->count;i++){
        printf("[%d]-[%p]\t", pre->data, pre->p);
        pre = pre->p;
    }

}

int removeData(linked_list* p, int n){
    if( n < 0 || n > (p->count+1)){
        printf("wrong position node is [%d] ~ [%d]\n", 0, p->count);
        return 0;
    }
    node* pre = &(p->start_node);
    
    if(n == p->count){   // 마지막삭제
        for(int i=1; i< p->count; i++) 
            pre = pre->p;
        free(pre->p);
        pre->p = NULL;
    }
    else if(n <= p->count){     // 중간삭제 
        node* tmp;              
        for(int i=1; i< n;i++){ // i< n == (마지막노드 -1)
           pre = pre->p;        // pre == (마지막 -1) 노드 주소
        }
        tmp = pre->p->p;
        free(pre->p);
        pre->p = tmp;
        
    }
    p->count--;
    return 1;
}
void deleteData(linked_list* p){
    node* pre = p->start_node.p;    //pre = 첫째 노드 주소
    node* next = pre->p;            //next == 첫째노드가 가리키는곳의 주소 == 둘째노드 주소
    
    while(p->count--){
        free(pre);          //첫째 삭제
        if(next){           // 다음주소가 널이 아니라면 == 마지막이 아니라면
            pre = next;     // 다음 삭제할 주소로 이동
            next = next->p;
        }
    }
    free(p);    //리스트본체도 삭제
    
}

