#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strlen()
#include <fcntl.h> // open(), creat()
#include <unistd.h> // read(), write(), close()
#define PIPE "/tmp/mypipe" // 1.
// 名前付きパイプの指定
int main(){
    char buf[80]; //= "From Server via named PIPE";
    int fd;
    fd = open(PIPE, O_RDONLY); // 2.
    if (fd == -1){
        fprintf(stderr, "PIPE does not exist! \n");
        exit(1);
    }
    while(read(fd, buf, sizeof(buf)) != 0){
        write(1, buf, strlen(buf));     //書き込み
        memset(buf, '\0', sizeof(buf)); //繰り返し用でbufを初期化
    }
    close(fd); // 4.
}