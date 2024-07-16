#include <stdio.h>

int main(){
    char buf[100]="¥0";
    
    printf("Content-type: text/html \n\n");
    printf("<pre>\n");
    scanf("%s", buf); // POSTによる入力
    printf("String from WWW client : \n");
    printf("%s \n",buf);
    printf("</pre>\n");
}