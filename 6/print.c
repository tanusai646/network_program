#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char buf[100]="\0";
    char *met1 = "GET";
    char *met2 = "POST";
    printf("Content-type: text/html \n\n");
    printf("<pre>\n");
    char *method = getenv("REQUEST_METHOD");
    printf("HTTP OK\n");
    
    if(method == NULL){
        printf("method error\n");
    } else if(strcmp(met1, method) == 0){
        printf("method = GET");
    } else if(strcmp(met2, method) == 0){
        printf("method == POST");
    }
    
    printf("</pre>\n");
}