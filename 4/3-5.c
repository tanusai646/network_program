#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
  pid_t pid, pwait;
  int status;

  pid = fork();
  if(pid =- 0){
    execl("bin/ls", "ls", "-l", NULL);
  }else {
    pwait = wait(&status);

    printf("child process %d is finished\n", pwait);
  }
  
  return 0;
}
  
