#include <stdio.h>
#include <string.h>     // strlen()に必要
#include <fcntl.h>      // open()に必要
#include <unistd.h>
// read(), write(), close()に必要

int main(){
    char buf[13];
    int fin, fout;
    fin = open("input2.dat", O_RDONLY);
    fout = open("output3.dat", O_WRONLY);

    // 入力ファイル指定
    while(read(fin, buf, sizeof(buf)) != 0){
        write(fout, buf, strlen(buf));  //書き込み
        memset(buf, '\0', sizeof(buf)); //繰り返し用でbufを初期化
    }
    write(fout, "\n", strlen("\n"));
    close(fin);
    close(fout);
}
