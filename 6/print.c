#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_for(){
    //GETで使う文字列ポインタ
    char *get_buf = getenv("QUERY_STRING");
    char *get_chn;
    char *p;

    printf("method = GET\n");
    printf("String from WWW client : \n");
    printf("%s \n", get_buf);
    //初回呼び出しをして、区切る
    get_chn = strtok(get_buf, "=");
    //区切った後半(=以降)を出力する
    while((get_chn = strtok(NULL, "")) != NULL){
        //tpがNULLを返すまで+を空白にする
        while((p = strchr(get_chn, '+')) != NULL){
            *p = ' ';
        }
        printf("original string\n");
        printf("%s\n", get_chn);
    }
}

void post_for(){
    //POSTで使う文字列ポインタ
    char post_buf[100]="\0";
    char *post_chn;
    char *p;

    printf("method == POST\n");
    scanf("%s", post_buf); // POSTによる入力
    printf("String from WWW client : \n");
    printf("%s \n",post_buf);
    //初回呼び出しをして、区切る
    post_chn = strtok(post_buf, "=");
    while((post_chn = strtok(NULL, "")) != NULL){
        //tpがNULLを返すまで+を空白にする
        while((p = strchr(post_chn, '+')) != NULL){
            *p = ' ';
        }
        printf("original string\n");
        printf("%s\n", post_chn);
    }
}

int main(){
    char *met1 = "GET";
    char *met2 = "POST";
    printf("Content-type: text/html\n\n");
    printf("<pre>\n");
    char *method = getenv("REQUEST_METHOD");
    
    if(method == NULL){
        printf("method error\n");
    } else if(strcmp(met1, method) == 0){
        get_for();
    } else if(strcmp(met2, method) == 0){
        post_for();
    }
    
    printf("</pre>\n");
}