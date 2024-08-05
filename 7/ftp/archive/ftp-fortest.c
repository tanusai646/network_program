/*222C1021 今村優希*/
/*ftp.c*/

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
    int sockfd, fd;
    struct sockaddr_in address;
    char buf[80] = "\0";
    char end[10] = "exit_send";
    //INETドメイン、ストリームソケットを利用
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    //サーバー情報を設定
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("131.206.37.50");
    address.sin_port = htons(50000);

    //クライアントからの接続要求とサーバ情報を確認
    //川原研のサーバーに接続
    int res = connect(sockfd, (struct sockaddr *)&address, sizeof(address));

    if(res == -1){
        perror("error\n");
        exit(1);
    }
    printf("\n * server IP: %s, port: %d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

    
    /*サーバーに学生番号を送信*/
    //第4回 server3.cの送受信部分を参考にする
    //server3,cはserverだけど、データを送信をするという面においては今回の学生番号を送るという動作に応用できる


    /*222C1021-copy.txtのオープン*/
    //第3回の授業の内容を使ってできる


    /*サーバからのデータ受信*/ 
    //入力がexit_sendになるまで読み込み、.txtに書き込む
    //第4回 client4.cのある条件まで読み込みをするという動作を応用してできる


    /*使ったものはちゃんとなおす*/
    close(fd);      //222C1021-copy.txtのクローズ
    close(sockfd);  //ソケットの除去

}