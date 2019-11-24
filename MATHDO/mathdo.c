#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
  int pid = fork(); // child1
  if (pid==0){ // child 1
    execlp("python", "python", "./add.py", argv[1], argv[2], NULL);
  } else // parent
  {
    int pid2 = fork();
    if (pid2==0){ // child 2
      execlp("/bin/sh", "sh", "mathdo.sh", argv[1], argv[2], NULL);
    
    } else 
    {
      int pid3 = fork();
      if (pid3 == 0) {
        execlp("java", "java", "Test", argv[1], argv[2], NULL);
      } else {
        int pid4 = fork();
        if (pid4 == 0) {
          execlp("node", "node", "./multiply.js", argv[1], argv[2], NULL);
        } else {
          wait(0);
          wait(0);
          wait(0);
          wait(0);
          printf("parent: done\n");
        }  
      }
    }    
  }
}
