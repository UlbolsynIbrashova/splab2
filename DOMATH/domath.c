// your code here
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
int main(int argc, char *argv[]){
    
  int x = atoi(argv[1]);  
  int y = atoi(argv[2]);  
  
  pid_t pid1 = fork();
  
  if (pid1 == 0) {
    printf("child_1: %d + %d = %d \n", x, y, x + y);
    exit(0);
  }    
  pid_t pid2 = fork();
  
  if (pid2 == 0) {
    printf("child_2: %d * %d = %d \n", x, y, x * y);
    exit(0);
  } 
  pid_t pid3 = fork();

  if (pid3 == 0) {
    printf("child_3: %d - %d = %d \n", x, y, x - y);
    exit(0);
  }    

  pid_t pid4 = fork();
  
  if (pid4 == 0) {
    printf("child_4: %d / %d = %d \n", x, y, x / y);
    exit(0);
  } 
      wait(pid1, NULL, 0);
      wait(pid2, NULL, 0);
      wait(pid3, NULL, 0);
      wait(pid4, NULL, 0);

  printf("parent: done.\n");

}
