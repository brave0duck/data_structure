#include <stdio.h>
#include "linked_stack.h"

char* reversSTring(char* src);

int main(int argc,char* argv[]){

    while(1){
        if(argc !=2){
            perror("[USAGE] ex01 [string] : \t - reverse string\n");
        }
        else{
            char * str = reversString(argv[1]);
            printf("%s\n",str);

            free(str);
            break;
        }
        
    }
    

    return 0;
}
char* reversString(char* src){


}