#include <stdio.h>

int fact(int x){
    if(x == 1){
        return 1;
    } else {
        return x * fact(x-1);
    }
}

int main(){
    int i = 1;
    printf("Contect-type: text/thml\n\n");
    printf("<pre>\n");

    do{
        printf("%3d! = %8d\n", i, fact(i));
        i++;
    } while(i <= 10);
        printf("</pre>\n");
}