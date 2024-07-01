#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h> 
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h> 


int main(){
    int sockfd_s, sockfd_c, i, n;
    struct sockaddr_in address_s;
    char buf[80] = "\0";

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

    //繰り返し
    while(1){
        //接続要求の許可と情報確認
        struct sockaddr_in address_c;
        unsigned int length_c = sizeof(address_c);
        sockfd_c = accept(sockfd_s, (struct sockaddr *)& address_c, &length_c);
        printf("\n * request from cluient IP: %s, port %d\n", inet_ntoa(address_c.sin_addr), ntohs(address_c.sin_port));

        //fork文
        if(fork() != 0) { // 子プロセス側の処理、送受信操作
            //read(sockfd_c, buf, sizeof(buf));
            //printf("\n* message from client: %s\n", buf);
            for(i = 0; i <= 10; i++){
                memset(buf, '\0', sizeof(buf));
                n = snprintf(buf, sizeof(i),"%d", i);
                printf("%s", buf);
                write(sockfd_c, buf, strlen(buf));
                sleep(1);
            }
            //strcpy(buf, "From Server via socket");
        }
        else{ // 親プロセス側の処理、要求受付
            
        }
        close(sockfd_c);
    }   //繰り返し終了

    //ソケットの除去
    close(sockfd_s);
 }