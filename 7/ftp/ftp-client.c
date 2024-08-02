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
    char error[] = "error";
    //INETドメイン、ストリームソケットを利用
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    //サーバー情報を設定
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("10.0.2.15");
    address.sin_port = htons(5000);

    //クライアントからの接続要求とサーバ情報を確認
    //サーバーに接続
    int res = connect(sockfd, (struct sockaddr *)&address, sizeof(address));

    if(res == -1){
        perror("error\n");
        exit(1);
    }
    printf("\n * server IP: %s, port: %d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

    //strcpy(buf, "client will connect to server");
    //write(sockfd, buf, strlen(buf));
    
    //サーバーに学生番号を送信
    printf("Your ID:");
    scanf("%s", buf);
    write(sockfd, buf, strlen(buf));

    //errorが出ていないか確認
    read(sockfd, buf, sizeof(buf));
    if(strcmp(buf, error) == 0){
        printf("the ID is wrong\n");
        exit(1);
    }

    /*222C1021-copy.txtのオープン*/
    printf("read start\n");
    fd = open("222C1021-test.txt", O_WRONLY);
    if(fd == -1){
        fprintf(stderr, "can't open the file\n");
        exit(1);
    }

    /*サーバからのデータ受信*/ 
    //入力がexit_sendになるまで読み込み、.txtに書き込む
    while(1){
        memset(buf, '\0', sizeof(buf)); // buf[]読み込み前に初期化
        read(sockfd, buf, sizeof(buf));
        write(fd, buf, strlen(buf));
        if(strstr(buf, end) == 0){
            printf("read finish\n");
            break;
        }
    } 


    close(fd);      //222C1021-copy.txtのクローズ
    close(sockfd);  //ソケットの除去

}