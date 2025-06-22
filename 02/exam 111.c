/**
 * double형의 점수를 입력받아 전체의 평균을 출력하는 프로그램
 * 조건  1. 사용자가 -1을 입력할때까지 반복 (입력한 숫자가 없는경우 = "1명 이상의 점수를 입력해야 합니다")
 *      2. double형 변수는 링크드리스트로 구현한다
 *      3. 평균값을 계산할때는 링크드 리스트에서 직접 값을 가져와서 계산한다
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct user{
    double score;
    struct user* plink;
}node;

typedef struct linked_list{
    node* pNode;
}list;

list* create();
int len(list* s);
int add(list* s, double score);
int print(list* s);
double average(list* s);
int delete(list* s);

int main(void){
    double score;
    int count=1;
    list* s = create();
    
    while(1){
        printf(">%d번째 점수는? (종료:-1): ", count);
        scanf("%lf[0-9^\n]",&score);

        if(score == -1){
            if(!len(s)){
                printf("1명 이상의 점수를 입력해야 합니다\n");
                continue;
            }
            else{
                break;
            }
        }
        if(!add(s,score)){
            printf("wrong input...try again\n");
            continue;
        }
        count++;
    }

    printf("%d명의 평균 : %6.3f",count-1, average(s));

    return 0;
}
list* create(){
    list* s = (list*)calloc(1,sizeof(list));
    return s;
}
int len(list* s){
    int count=0;
    node * p = s->pNode;
    while(p){
        p = p->plink;
        count++;
    }
    return count;
}
int add(list* s, double score){
    node* p = s->pNode;
    while(p)
        p = p->plink;
    
    node* new = calloc(1,sizeof(node));
    if(new){
        p = new;
        new->score = score;
        new->plink = NULL;
        return 1;
    }
    else{
        return 0;
    }
}
double average(list* s){
    double total=0.0f;
    int count;
    node* p = s->pNode;
    while(p){
        total += p->score;
        p = p->plink;
        count++;
    }

    return total / (double)count;
}
int print(list* s){
    int count=0;
    node* p = s->pNode;
    while(p){
        printf("[%6.3f]\t", p->score);
        p = p->plink;
        count++;
    }
    printf("node count : %d\n",count);
    return count;

}
int delete(list* s){
    int count = len(s);
    if(count > 0){                  // node가 하나라도 있을경우에만
        node* pre = s->pNode;       //pre = 첫째 노드 주소만
        node* next = pre->plink;    //next == 첫째노드가 가리키는곳의 주소 == 둘째노드 주소
        
        while(count--){
            free(pre);          //첫째 삭제
            if(next){           // 다음주소가 널이 아니라면 == 마지막이 아니라면
                pre = next;     // 다음 삭제할 주소로 이동
                next = next->plink;
            }
        }

    }
    free(s);    //리스트본체도 삭제
    

}