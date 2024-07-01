/*222C1021 今村優希*/
/*server.c*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strlen()
#include <fcntl.h> // open(), creat()
#include <unistd.h> // read(), write(), close()
#define PIPE "/tmp/mypipe" // 1.
// 名前付きパイプの指定
int main(){
    char buf[80] = "From Server via named PIPE\n";
    int fd;
    fd = open(PIPE, O_WRONLY); // 2.
    if (fd == -1){
        fprintf(stderr, "PIPE does not exist! \n");
        exit(1);
    }
    write(fd, buf, strlen(buf)); // 3.
    close(fd); 
}
