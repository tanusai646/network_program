#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char buf[100] = "\0"; // 文字列読込
    char *method, *temp; // method名、文字列操作用
    printf("Content-type: text/html \n\n");
    method = getenv("REQUEST_METHOD"); // 1) GET/POSTの取得とINPUTタグのname名の削除
    if(method == NULL){
        printf("method error\n");
        exit(1);
    } else if(strcmp(method, "GET") == 0) // GETの場合 〜 環境変数から文字列取得
        strcpy(buf, getenv("QUERY_STRING"));
    else if(strcmp(method, "POST") == 0) // POSTの場合 〜 標準入力から文字列読込
        scanf("%s", buf);
    temp = strtok(buf, "="); // 2) 文字列 “*****=“ の除去 (※ name名が何でも対応)
    printf("<pre>¥n");
    while(temp != NULL){ // 3) スペースから変換された ‘+‘ の除去
        temp = strtok(NULL, "+");
        if(temp != NULL) printf("%s ", temp); // 入力文字列のみを表示
    } // ～ GET/POSTどちらでもスペース入り文字列に対応
    printf("</pre>¥n");
}