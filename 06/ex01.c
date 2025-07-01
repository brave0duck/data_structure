#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_stack.h"


int main(int argc,char* argv[]){

    LinkedStack* pStack=NULL;
    LinkedStackNode* pNode = NULL;
    char input[100]={0};

    printf("Input string (exit:0) : ");
    fgets(input, 100,stdin);
    input[strcspn(input, "\n")] = 0; // 개행 제거

    while(input[0] !='0'){
        char* str = reversString(input);
        if(str != NULL){
            printf("%s\n",str);
            free(str);
        }
    
        fflush(stdin);
        printf("Input string (exit:0) : ");
        fgets(input, 100,stdin);
        input[strcspn(input, "\n")] = 0; // 개행 제거
    }

    return 0;
}
char* reversString(char* src){
    LinkedStack* pStack=NULL;
    LinkedStackNode* pNode = NULL;

    int size = strlen(src);
    char* result = (char*)calloc(size+1,sizeof(char));    //include '\0'

    if(result == NULL)
        return NULL;

    pStack = createLinkedStack();
    
    for(int i=0; i < size; i++){
       pushLS(pStack,src[i]);
    }
    for(int i=0; i < size; i++){
       pNode = popLS(pStack);
       result[i] = pNode->data;
       free(pNode);
    }
    deleteLinkedStack(pStack);

    return result;
}