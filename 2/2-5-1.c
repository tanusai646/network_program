#include <stdio.h>

void print_v(int n){
    printf("Value = %d\n", n);
    n = 100;
}

int main(){
    int i = 10;
    print_v(i);
    printf("Value = %d\n", i);
}