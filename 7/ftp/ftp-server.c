/*222C1021 今村優希*/
/*server3.c*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h> 
#include <fcntl.h>
#include <unistd.h>


int main(){
    int sockfd_s, fd, pid, pwait;
    struct sockaddr_in address_s;
    char buf[80] = "\0";
    char txt[] = ".txt";
    char end[10] = "exit_send";

    //INETドメイン、ストリームソケットを利用
    sockfd_s = socket(AF_INET, SOCK_STREAM, 0);

    //サーバソケット=(IP: 10.0.2.15, ポート:5000)に設定
    address_s.sin_family = AF_INET;
    address_s.sin_addr.s_addr = inet_addr("10.0.2.15");
    address_s.sin_port = htons(5000);

    bind(sockfd_s, (struct sockaddr *)&address_s, sizeof(address_s));

    //要求受付の準備
    listen(sockfd_s, 5);
    printf("sertver waits\n");

    //接続要求の許可と情報確認
    struct sockaddr_in address_c;
    unsigned int length_c = sizeof(address_c);

    /*子プロセスでファイルの送受信を行う*/
    pid = fork();
    while(1){
        int sockfd_c = accept(sockfd_s, (struct sockaddr *)& address_c, &length_c);
        pid = fork();
        if(pid == 0){
            printf("\n * request from client IP: %s, port %d\n", inet_ntoa(address_c.sin_addr), ntohs(address_c.sin_port));
            //学生番号の取得
            memset(buf, '\0', sizeof(buf));
            read(sockfd_c, buf, sizeof(buf));
            //printf("\n* message from client: %s\n", buf);
            
            //学生番号と.txtを結合
            strcat(buf, txt);
            printf("%s\n", buf);    //debug
            fd = open(buf, O_RDONLY);
            if(fd == -1){
                printf("file can't the open\n");
                exit(1);
            }
            //strcpy(buf, "From Server via socket");
            //write(sockfd_c, buf, strlen(buf));
            printf("start write\n");
            while(1){
                memset(buf, '\0', sizeof(buf)); // buf[]読み込み前に初期化
                read(fd, buf, sizeof(buf));     //ファイルの内容をbufに格納
                write(sockfd_c, buf, strlen(buf));//送信
                if(strstr(buf, end) != NULL){
                    printf("finished write\n");
                    break;
                }
            } 
            close(sockfd_c);
            close(sockfd_s);

            exit(1);
        } else{
            int status;
            pwait = waitpid(-1, &status, WNOHANG);
            printf("sarver wait\n");
        }
    }

    //送受信操作


    //ソケットの除去

 }