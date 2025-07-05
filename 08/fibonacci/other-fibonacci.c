#include <stdio.h>
#include <stdint.h>
//  f
//  1   2   3   4   5   6   7   8   9   10
//  0   1   1   2   3   5   8   13  21  34
unsigned long long fibonacci(int n){

    uint64_t one=0, two=1;
    uint64_t tmp;
    for(int i=3; i <= n; i++){
        tmp = two;          //tmp=1     1       2       3       5       8       13      21
        two = two + one;    //tow=1     2       3       5       8       13      21      34
        one = tmp;          //one =1    1       2       3       5       8       13      21
        
    }
    return two;
    
}
int main(int argc,char* argv[]){

    int input;
    printf("===========================\n");
    printf("==== f.i.b.o.n.a.c.c.i ====\n");
    printf("===========================\n");
    while(1){
        printf("\ninput number [exit:0] : ");
        scanf("%d", &input);
        if(input==0){
            break;
        }
        printf("\nresult = %llu\n",fibonacci(input));
    }
    return 0;
}