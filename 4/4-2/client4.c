/*222C1021 今村優希*/
/*client4.c*/

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
    int sockfd, i;
    struct sockaddr_in address;
    char buf[80] = "\0";

    //INETドメイン、ストリームソケットを利用
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    //サーバー情報を設定
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("10.0.2.15");
    address.sin_port = htons(5000);

    //クライアントからの接続要求とサーバ情報を確認
    int res = connect(sockfd, (struct sockaddr *)&address, sizeof(address));

    if(res == -1){
        perror("error\n");
        exit(1);
    }
    
    while(i != 10){ //i=10になったら読み込み終了
        // サーバからのデータ受信
        memset(buf, '\0', sizeof(buf)); // buf[]読み込み前に初期化
        read(sockfd, buf, sizeof(buf));
        i = atoi(buf);
        printf("\n * message from server : %d \n", i);
    }
    //ソケットの除去
    close(sockfd);
}