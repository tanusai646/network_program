#include <stdio.h>

int main(){
    int a, b;
    int *pt;
    printf("a = %d, b = %d, *pt = %d\n", a, b, *pt);
    a = 123;
    pt = &a;
    b = *pt;
    
    printf("a = %d, b = %d, *pt = %d\n", a, b, *pt);

    pt = &b;
    /*演習1*/
    *pt = 999; //bに関節的に999を代入

    printf("a = %d, b = %d, *pt = %d\n", a, b, *pt);
}