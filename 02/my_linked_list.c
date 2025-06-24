#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ll_node{     // ll_node == linked list node
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
int getLen2(linked_list* p);
void printData(linked_list* p);
void concatList(linked_list* a, linked_list* b);
void reverse(linked_list* p);

int main(int argc, char* argv[]){
    linked_list* a=NULL;
    linked_list* b=NULL;

    a = create();
    b = create();

    addData(a,1,10);
    addData(a,2,20);
    addData(a,3,30);
    addData(b,1,40);
    addData(b,2,50);

    printf("before concatate\n");
    printf("[linked list a]\n");
    printData(a);
    printf("[linked list b]\n");
    printData(b);

    concatList(a,b);

    printf("After concatate\n");
    printf("[linked list a]\n");
    printData(a);
    printf("[linked list b]\n");
    printData(b);

    printf("reverse List...\n");
    reverse(a);
    printData(a);
    printf("re-reverse List...\n");
    reverse(a);
    printData(a);
    
    deleteData(a);
    deleteData(b);


    // linked_list * pList = NULL;
    // int value=0;

    // pList = create();
    // addData(pList,1,10);
    // addData(pList,2,20);
    // addData(pList,2,30);

    // printData(pList);

    // deleteData(pList);
    

    return 0;
}
linked_list* create(void){
    linked_list* p  = (linked_list*)calloc(1,sizeof(linked_list));
    return p;
}
// concatate two linked list. 1. find end-point for a  2.link a and b
void concatList(linked_list* a, linked_list* b){
    node* p = a->start_node.p;
    if(a != NULL && b != NULL){
        while(p && p->p){
            p = p->p;
        }
        p->p =  b->start_node.p;
        a->count += b->count;
        b->start_node.p = NULL;
        b->count =0;
    }
}
int getData(linked_list* p, int n){
    node * tmp = &(p->start_node);
    for(int i=1; i<=n;i++)
        tmp = tmp->p;
    return tmp->data;
}

int addData(linked_list* p, int n, int data){
    if( n < 1 || n > (p->count+1)){
        printf("%dis wrong position. node count [%d]\n",n, p->count);
        return 0;
    }
    node* pre = &(p->start_node);
    node* new = calloc(1,sizeof(node));

    if(n > p->count){           // 마지막에 추가하는경우
        for(int i=1; i<= p->count; i++){
            pre = pre->p;       // pre = 마지막 노드
        }
        new->p = NULL;
        pre->p = new;
        new->data = data;
    }
    else if(n <= p->count){     // 중간에 끼우는경우. 
                                // 1.할당 2.할당p = (마지막노드 -1) p  3.마지막-1노드 = 할당p
        for(int i=1; i< n;i++){ 
           pre = pre->p;        // pre == (마지막 -1) 노드
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
int getLen2(linked_list* p){
    node* node = p->start_node.p;
    int count=0;
    while(node){
        node = node->p;
        count++;
    }
    return count;
}
void printData(linked_list* p){
    node* pre = p->start_node.p;
    for(int i=1; i<= p->count;i++){
        printf("[%d]-%d\n", i, pre->data);
        pre = pre->p;
    }
    printf("node count : %d\n", getLen2(p));

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
    
    if(p->count > 0){                   // node가 하나라도 있을경우에만
        node* pre = p->start_node.p;    //pre = 첫째 노드 주소만
        node* next = pre->p;            //next == 첫째노드가 가리키는곳의 주소 == 둘째노드 주소
        
        while(p->count--){
            free(pre);          //첫째 삭제
            if(next){           // 다음주소가 널이 아니라면 == 마지막이 아니라면
                pre = next;     // 다음 삭제할 주소로 이동
                next = next->p;
            }
        }

    }
    free(p);    //리스트본체도 삭제
    
}
// 리스트를 역순으로 바꾸는 함수
void reverse(linked_list* p){
    node* start = p->start_node.p;      // 포인터 3개 필요
    node* next = start->p;              // 시작주소 - start, 다음주소-next, 다음주소의 다음주소-tracker
    node* tracker = next->p;

    start->p = NULL;                    // 이제 1번노드는 마지막노드이므로 주소칸에 NULL

    while(start != NULL && next !=NULL){
        if(tracker != NULL){            // 마지막노드 만날때까지 반복
            next->p = start;            // 리버스방향이므로 A->B가 아닌 B->A. B의 링크에 A의 주소 저장
            start = next;               // 다음칸으로 이동
            next = tracker;
            tracker = next->p;
        }
        else{                           // 마지막에 도달하면. 마지막노드 주소 저장한후. 헤더노드와 연결
            next->p = start;
            p->start_node.p = next;
            break;
        }
   }
    
}
