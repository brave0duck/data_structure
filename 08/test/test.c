#include <stdio.h>

int factorial(int n){
    int ret=0;
    if(n>=1){
        ret = n * factorial(n-1);
    }
    else{
        ret =1;
    }
    return ret;
}
void recursive(int n){
    if(n>1){
        recursive(n/2);
        recursive(n/2);
    }
    printf("%i\n",n);
}
int four(int n){
    printf("%d\n",n);
    if(n<=1)
        return 1;
    
    return n + four(n-1);
}
double five(double n){
    if(n <= 0)
        return 1;
    return 1/five(n-2) + 1/five(n-1);
}
double harmonic(double n) {
    if (n <= 1)
        return 1.0;
    return 1.0 / n + harmonic(n - 1);
}
int main(void){
    printf("four result = %f\n\n", harmonic(10));
    //printf("four result = %d\n\n", four(100));
    return 0;
}