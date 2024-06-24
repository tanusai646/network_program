#include <stdio.h>
#include <unistd.h> // fork(),exec()に必要
#include <sys/types.h> // fork(),wait()に必要
#include <sys/wait.h> // wait()に必要
int main(){
    pid_t pid, pwait; // fork() ,wait() の戻り値
    int status; // 子プロセスの終了状態
    pid = fork(); // 1. 子プロセスの生成
    if(pid == 0) // 自分が子プロセスと判断
    execl("/bin/ls","ls", "-l", NULL);
    // 2. コマンド ls の実行
    else{ // 自分が親プロセスと判断
    pwait = wait(&status);
    // 3. 子プロセスの終了待機
    printf("child process %d is finished¥n", pwait);
    }
}