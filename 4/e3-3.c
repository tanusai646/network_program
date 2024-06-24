#include <stdio.h>
#include <string.h> // strlen()に必要
#include <fcntl.h> // open()に必要
#include <unistd.h>
// read(), write(), close()に必要
int main(){
    char buf[13];
    // ※1. 演習3で、サイズは変えない！
    int fin, fout;
    fin = open("input2.dat", O_RDONLY);
    fout = open("output3.dat", O_WRONLY);
    /*if(fout < 0){
        fout = open("output3.dat", O_CREAT);
    }*/
    // 入力ファイル指定
    while(read(fin, buf, sizeof(buf)) != 0){
        write(fout, buf, strlen(buf));
        memset(buf, '\0', sizeof(buf));
    }
    write(fout, "\n", strlen("\n"));
    //printf("fout = %d\n", fout);
    close(fin);
    close(fout); // ※2. 繰り返し時は、
}
