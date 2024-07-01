#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h> 
#include <fcntl.h>
#include <unistd.h>


int main(){
    int sockfd_s;
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

    //接続要求の許可と情報確認
    struct sockaddr_in address_c;
    unsigned int length_c = sizeof(address_c);

    int sockfd_c = accept(sockfd_s, (struct sockaddr *)& address_c, &length_c);

    printf("\n * request from cluient IP: %s, port %d\n", inet_ntoa(address_c.sin_addr), ntohs(address_c.sin_port));

    //送受信操作
    memset(buf, '\0', sizeof(buf));
    read(sockfd_c, buf, sizeof(buf));
    printf("\n* message from client: %s\n", buf);

    strcpy(buf, "From Server via socket");
    write(sockfd_c, buf, strlen(buf));

    //ソケットの除去
    close(sockfd_c);
    close(sockfd_s);
 }