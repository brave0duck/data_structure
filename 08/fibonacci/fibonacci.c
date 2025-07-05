#include <stdint.h>
#include <stdio.h>

int fibonacci(int n){
    if(n <=1)
        return n;

    return fibonacci(n-2) + fibonacci(n-1);
}
int main(int argc,char** argv){
    
    for(int i=1; i <=10 ;i++){
        printf("fibonacci(%d) = %d\n", i, fibonacci(i-1));
    }
    
    return 0;
}

