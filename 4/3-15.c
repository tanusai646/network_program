#include <stdio.h> // fprintf()の利用に必要
#include <stdlib.h>
#include <unistd.h> // fork(),exec()
#include <sys/types.h> // fork(),wait() に必要
#include <sys/wait.h> // wait() に必要
#include <fcntl.h> // creat(),close() に必要
int main()
{
    int fd; // 出力ファイル記述子
    pid_t pwait; // wait() からの戻り値
    int status; // 子プロセスの終了状態
    if(fork() == 0) { // 子プロセス側の処理（※ 事前にtemp.txt 作成）
        fd = open("temp.txt", O_WRONLY); // i. “temp.txt” のオープン
        close(1); // ii. 標準出力を閉じる
        dup(fd); // iii. “temp.txt”への出力を「標準出力」にコピー
        close(fd); // iv. 不要な記述子を閉じる
        execl("/bin/ps","ps",NULL); // 5. ps コマンドの実行
        fprintf(stderr,"cannot execute command\n"); 
        exit(1);
    // ※ execl() 失敗時は if 文を抜ける
    }
    else{ // 親プロセス側の処理
        pwait = wait(&status);
        printf("child process %d is finished\n", pwait);
    }
}
