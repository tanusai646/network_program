#include <stdio.h>      // fprintf()の利用に必要
#include <stdlib.h>
#include <unistd.h>     // fork(),exec()
#include <sys/types.h>  // fork(),wait() に必要
#include <sys/wait.h>   // wait() に必要
#include <fcntl.h>      // creat(),close() に必要

int main()
{
    int fd[2];
    pid_t pwait;        // wait() からの戻り値
    int status;         // 子プロセスの終了状態

    if(pipe(fd) == -1){ // 単方向パイプの作成
        perror("pipe"); 
        exit(1);
    }

    if(fork() == 0) {
	    close(fd[0]);   //不要なパイプを閉じる

        close(1);       //標準出力を閉じる
        dup(fd[1]);     //パイプfd[1]をコピー

        close(fd[1]);   //不要なパイプfd[1]を閉じる
        execl("/bin/ls","ls","-l",NULL); // 

        fprintf(stderr,"cannot ls command\n"); 
        exit(1);        //execl() 失敗時は if 文を抜ける
    }
    else{               // 親プロセス側の処理
        pwait = wait(&status);  //子プロセス待ち
        printf("child process %d is finished\n", pwait);

        close(fd[1]);   //不要なパイプを閉じる
        close(0);       //標準入力を閉じる
        dup(fd[0]);     //パイプfd[0]をコピー

        close(fd[0]);   //不要なパイプfd[0]を閉じる
        execl("/bin/grep","grep","put", NULL);

        fprintf(stderr,"cannot grep command\n"); 
        exit(1);
    }
}
