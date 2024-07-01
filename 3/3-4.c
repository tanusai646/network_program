#include <stdio.h>
#include <string.h> // strlen()に必要
#include <fcntl.h> // open()に必要
#include <unistd.h>
// read(), write(), close()に必要
int main(){
    char buf[13];
    // ※1. 演習3で、サイズは変えない！
    int fd;
    fd = open("input2.dat", O_RDONLY);
    // 入力ファイル指定
    read(fd, buf, sizeof(buf));
    write(1, buf, strlen(buf));
    close(fd); // ※2. 繰り返し時は、
} // memset() でbuf[] を初期化