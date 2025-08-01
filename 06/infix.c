/* infix.c = 후위연산자를 구현
ex) A + (B * C) 이것이 인간의 수식
BUT 컴퓨터는 ABC*+ 이런식으로 계산함

스택을 이용한다


로직 - 
1. 문자열을 입력받는다
    1-1. 끝까지 돌면서 연산자를 만날때까지 하나씩 이동
    1-2. 연산자를 만나면 스택에서 두 요소를 꺼내서 연산을 한다 ( pop())
    1-3. 연산결과를 스택에 푸쉬한다 ( push())
    1-4. 연산자가 없다. or 끝까지 다 돌았다
    1-5. 스택에 있는 결과를 출력한다

*/
#include "infix.h"
#define MAX 50

int main(int argc, char* argv[]){
    LinkedStack* pStack=NULL;
    LinkedStackNode* pNode = NULL;
    pStack = create();      // create stack
    char input[MAX]={0};    // for input buffer
    
    printf("infix operation input (max:50,exit:0) : "); // user input
    fgets(input, MAX,stdin);
    input[strcspn(input, "\n")] = 0; // remove null
    

    while(input[0] !='0'){      // exit : 0
        printf("result = %f\n", calcToken(pStack,input));
        memset(input,0,MAX);
    
        fflush(stdin);
        printf("infix operation input (max:50, exit:0) : ");
        fgets(input, MAX,stdin);
        input[strcspn(input, "\n")] = 0; // remove null
    }

    delete(pStack);

    return 0;
}    
double operation(double a, double b, char op){          // ex) operation(3.0, 4.0, '+')  = 3 + 4
    if(op == '*')
        return a*b;
    else if(op == '/')
        return a/b;
    else if(op == '+')
        return a+b;
    else if(op == '-')
        return a-b;
    else
        return 0.0;
}
double calcToken(LinkedStack *pStack, char* src){
    LinkedStackNode* p1, *p2;       // for pop extract
    char op;                        // save operator
    if(pStack != NULL){
        for(int i=0; i < strlen(src); i++){
            
            LinkedStackNode* pNode = calloc(1,sizeof(LinkedStackNode));
            switch (src[i])
            {   
                case '*':           // if meet operator, 2 pop()
                case '/':
                case '+':
                case '-':
                {                   
                    op = src[i];
                    p1 = pop(pStack);
                    p2 = pop(pStack);
                    if(p1 != NULL && p2 != NULL){
                        pNode->data.value  = operation(p2->data.value, p1->data.value, op);
                        if(pNode->data.value != 0.0)
                            push(pStack, pNode);        // operation and result re-push()
                    }
                    else{
                        printf("operation error... should be operand\n");
                    }
                    free(p1);
                    free(p2);
                    break;
                }   
                default:            // if meet number, 1 push()
                {
                    op = src[i];
                    pNode->data.value = (double) (op - '0');        // ex) '1' - '0' = 1. transfomation character'9' -> double 9.0
                    push(pStack, pNode);
                    break;
                }
            }
        }
    }
    return pStack->pTop->data.value;

}


LinkedStack* create(){               //생성
    LinkedStack* pStack = calloc(1,sizeof(LinkedStack));
    if(pStack == NULL){
        return NULL;
    }
    return pStack;
}
int push(LinkedStack* pStack, LinkedStackNode* pNode){     //푸시. 메모리할당->링크 연결 ->끝
    if(pStack != NULL && pNode != NULL){
            pNode->pLink = pStack->pTop;
            pStack->pTop = pNode;
            pStack->currentCount++;
            return 0;
    }
    return 1;
}
LinkedStackNode* pop(LinkedStack* pStack){        //팝.  링크재연결->탑링크 주소 반환. 받은쪽이해제
    LinkedStackNode * pNode;
    if(pStack != NULL){
        pNode = pStack->pTop;
        pStack->pTop = pNode->pLink;
        pStack->currentCount--;
        
        pNode->pLink = NULL;
    }
    return pNode;
}
static inline int isEmpty(LinkedStack* pStack){ // 비었나확인. 비었으면 1, 아니면 0
    if(pStack!=NULL && pStack->currentCount > 0)
            return 0;
    return 1;
}
LinkedStackNode* peek(LinkedStack* pStack){   //피크. pTop주소반환
    return pStack->pTop;
}
void delete(LinkedStack* pStack){
    if(pStack != NULL){
        LinkedStackNode* pDel = pStack->pTop;
        LinkedStackNode* pNext;
        while(pDel){
            pNext = pDel->pLink;
            free(pDel);
            pDel = pNext;
        }
        free(pStack);
    }
}
void display(LinkedStack* pStack){
    if(pStack != NULL){
        LinkedStackNode* p = pStack->pTop;
        int count = pStack->currentCount;
        printf("Node count : %d\n",count);
        while(p){
            printf("[%d] - [%c]\n", count--, p->data);
            p = p->pLink;
        }
    }
    
}
