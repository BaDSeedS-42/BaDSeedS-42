#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*#include <string.h>
  #include <sys/wait.h>*/

int main(int argc, char **argv)
{
  int i, n, t;
  pid_t pid1;
  
  n=atoi(argv[1]);
  t=atoi(argv[2]);
  /*
  for(i=0; i<n; i++){
    if(fork())
      printf("PID=%d", getpid());
    if(fork())
      printf("PID=%d", getpid());
    if(wait(int *statLoc))
      printf("PID=%d", getpid());
    if(wait(int *statLoc))
      printf("PID=%d", getpid());
  }
  sleep(t);
  printf("Finito!");*/

  for(i=0;i<n; i++){
    pid1=fork();
    if(pid1>0){
      pid1=fork();
      if(pid1>0)
	return 0;
    }
  }
  sleep(t);
  printf("Finito!");
  return 0;
}
